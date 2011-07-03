#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <boost/thread/locks.hpp>
#include <iostream>
#include <sstream>
#include <time.h>

#include "token_dispatch.h"

namespace tw { namespace test {

TokenContext::TokenContext(const std::string &userId, const std::string &token, const int32_t expireTime)
    : mUserId(userId), mToken(token), mExpireTime(expireTime)
{
    mKey = mUserId + '-' + mToken;
}

TokenContext::~TokenContext()
{
}

void TokenContext::showInfo(void)
{
    printf("key: %s -> expireTime: %d, token: %s, userId: %s\n",
            this->mKey.c_str(), this->mExpireTime, this->mToken.c_str(), this->mUserId.c_str());
}

bool operator<(const TokenContextPtr a, const TokenContextPtr b)
{
    return a->mExpireTime >= b->mExpireTime;
}

TokenManager::TokenManager(std::string host) : mHost(host)
{
}

TokenManager::~TokenManager()
{
}

std::string TokenManager::genToken(void)
{
    boost::uuids::uuid token = boost::uuids::random_generator()();
    std::stringstream s;

    s << token;
    return s.str();
}

ErrorCode TokenManager::insertContext(TokenContextPtr context)
{
    boost::lock_guard<boost::mutex> lock(this->mMutex);

    mContextDB.insert(std::pair<std::string, TokenContextPtr >(context->mKey, context));
    mContextQueue.push(context);

    /*
    for(std::map<std::string, TokenContextPtr >::iterator it=mContextDB.begin(); it !=mContextDB.end(); it++) {
        printf("key: %s -> expireTime: %d, token: %s, userId: %s\n",
                it->first.c_str(), (it->second)->mExpireTime, (it->second)->mToken.c_str(), (it->second)->mUserId.c_str());
    }
    */
    return SUCCESS;
}

ErrorCode TokenManager::removeContext(const std::string &token)
{
    boost::lock_guard<boost::mutex> lock(this->mMutex);
    std::map<std::string, TokenContextPtr>::iterator it = mContextDB.find(token);

    if(it != mContextDB.end()) {
        mContextDB.erase(it);
        return SUCCESS;
    }
    return CANT_FOUND_TOKEN;
}

ErrorCode TokenManager::isTokenOK(const std::string &token)
{
    boost::lock_guard<boost::mutex> lock(this->mMutex);
    std::map<std::string, TokenContextPtr>::iterator it = mContextDB.find(token);

    if(it == mContextDB.end())
        return CANT_FOUND_TOKEN;
    return SUCCESS;
}

std::string TokenManager::genURL(const std::string &token, const std::string &itemKey)
{
    std::string uuid(itemKey);

    if(itemKey == "")
        uuid = this->genToken();
    return mHost + "/" + token + "-" + uuid;
}

int32_t TokenManager::checkExpireContext(void)
{
    boost::lock_guard<boost::mutex> lock(this->mMutex);

    while(mContextQueue.size() > 0) {
        TokenContextPtr context = mContextQueue.top();
        time_t now = time(NULL);

        if(context->mExpireTime > now) {
            return context->mExpireTime - now;
        }

        context->showInfo();
        std::map<std::string, TokenContextPtr>::iterator it = mContextDB.find(context->mKey);
        if(it != mContextDB.end())
            mContextDB.erase(it);
        else printf("not found\n");
        mContextQueue.pop();
    }
    return 0;
}

void TokenManager::showInfo(void)
{
    printf("Show Map:\n");
    for(std::map<std::string, TokenContextPtr >::iterator it=mContextDB.begin(); it !=mContextDB.end(); it++) {
        it->second->showInfo();
        /*
        printf("key: %s -> expireTime: %d, token: %s, userId: %s\n",
                it->first.c_str(), (it->second)->mExpireTime, (it->second)->mToken.c_str(), (it->second)->mUserId.c_str());
                */
    }

    printf("Queue:\n");
    while(mContextQueue.size() > 0) {
        TokenContextPtr context = mContextQueue.top();

        context->showInfo();
        /*
        printf("key: %s -> expireTime: %d, token: %s, userId: %s\n",
                context->mKey.c_str(), context->mExpireTime, context->mToken.c_str(), context->mUserId.c_str());
                */
        mContextQueue.pop();
    }
}
}}
