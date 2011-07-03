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
    mKey = mUserId + '_' + mToken;
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

ErrorCode TokenManager::insertToken(TokenContextPtr context)
{
    boost::lock_guard<boost::mutex> lock(this->mMutex);

    mContextDB.insert(std::pair<std::string, TokenContextPtr >(context->mKey, context));
    // only insert context which can expire
    mContextQueue.push(context);

    /*
    for(std::map<std::string, TokenContextPtr >::iterator it=mContextDB.begin(); it !=mContextDB.end(); it++) {
        printf("key: %s -> expireTime: %d, token: %s, userId: %s\n",
                it->first.c_str(), (it->second)->mExpireTime, (it->second)->mToken.c_str(), (it->second)->mUserId.c_str());
    }
    */
    return SUCCESS;
}

ErrorCode TokenManager::removeToken(const std::string &token)
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

/* there two type of URL:
 * <userId>_<token>_<item key> for expire url
 * P<userId>_<token>_<item key> for persistent url
 *
 * the url will expire when token is expired if expireTime > 0
 */
std::string TokenManager::genURL(const std::string &token, const std::string &itemKey, const int32_t expireTime)
{
    std::string uuid(itemKey);

    if(itemKey == "")
        uuid = this->genToken();
    // FIXME the url host part will be determined by routing table
    if(expireTime > 0)
        return mHost + "/" + token + "_" + uuid;
    else
        // for persistent url
        return mHost + "/P" + token + "_" + uuid;
}

ErrorCode TokenManager::checkURL(const std::string &url)
{
    size_t pos = url.rfind("/");

    if(pos != std::string::npos) {
        if(pos + 1 < url.size()) {
            // it is persistent url
            if(url[pos+1] == 'P') {
                printf("persistent url\n");
                return SUCCESS;
            }
            else {
                // get token part from url
                size_t token_end = url.find("_", url.find("_", pos+1) + 1);
                printf("url token is: %s\n", url.substr(pos + 1, (token_end - pos -1)).c_str());
                return isTokenOK(url.substr(pos + 1, (token_end - pos -1)));
            }
        }
        return URL_FORMAT_ERROR;
    }
    return URL_FORMAT_ERROR;
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
