#ifndef token_dispatch_header_h

#define token_dispatch_header_h

#include <string>
#include <queue>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>

#include "gen-cpp/proto_types.h"
#include <common/singleton.h>

#include <service/token/context.h>

namespace service { namespace token {

class TokenManager /*: common::Singleton<TokenManager>*/
{
public:
	enum ErrorCode {
	    SUCCESS,
	    LOGIN_FAIL,
	    CANT_FOUND_REPO,
	    CANT_FOUND_TOKEN,
	    URL_EXPIRE,
	    URL_FORMAT_ERROR,
	};
public:
    static TokenManager* instance()
    {
    	TokenManager* m_instance = NULL;
        if(!m_instance)
        {
        	m_instance = new TokenManager;
        }

        return m_instance;
    }
private:
    TokenManager(std::string host="localhost");
public:
    virtual ~TokenManager();

    std::string genToken();
    ErrorCode insertToken(service::token::ContextPtr context);
    ErrorCode removeToken(const std::string &token);
    ErrorCode isTokenOK(const std::string &token);
    std::string genURL(const std::string &token, const std::string &itemKey, const int32_t expireTime=0);
    int32_t checkExpireContext(void);
    ErrorCode checkURL(const std::string &url);
    void showInfo(void);

private:
    std::priority_queue<service::token::ContextPtr > mContextQueue;
    std::map<std::string, service::token::ContextPtr > mContextDB;
    std::string mHost;
    boost::mutex mMutex;
};

} /*token*/ } /*service*/


#endif
