/*
 * tokencontext.h
 *
 *  Created on: 2011/7/3
 *      Author: maple
 */

#ifndef TOKENCONTEXT_H_
#define TOKENCONTEXT_H_

#include <global.h>

namespace service { namespace token {

struct Context
{
	Context(const std::string &userId, const std::string &token, const int32_t expireTime = 0)
		: mUserId(userId), mToken(token), mExpireTime(expireTime)
	{
		mKey = mUserId + '_' + mToken;
	}

    ~Context(){};

//    bool operator<(const TokenContext &) const;
    void showInfo(void)
    {
        printf("key: %s -> expireTime: %d, token: %s, userId: %s\n",
                this->mKey.c_str(), this->mExpireTime, this->mToken.c_str(), this->mUserId.c_str());
    }

    std::string mKey;
    std::string mUserId;
    std::string mToken;
    int32_t mExpireTime;
};

typedef SHARED_PTR(Context) ContextPtr;

} /*token*/ } /*service*/

#endif /* TOKENCONTEXT_H_ */
