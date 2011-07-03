#ifndef token_dispatch_header_h

#define token_dispatch_header_h

#include <string>
#include <queue>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>

#include "error.h"
#include "proto_types.h"
//#include "data_store.h"

using boost::shared_ptr;

namespace tw { namespace test {

struct TokenContext
{
    TokenContext(const std::string &userId, const std::string &token, const int32_t expireTime);
    ~TokenContext();

//    bool operator<(const TokenContext &) const;
    void showInfo(void);

    std::string mKey;
    std::string mUserId;
    std::string mToken;
    int32_t mExpireTime;
};

typedef shared_ptr<TokenContext> TokenContextPtr;

class TokenManager
{
public:
    TokenManager(std::string host="localhost");
    virtual ~TokenManager();

    std::string genToken();
    ErrorCode insertContext(TokenContextPtr context);
    ErrorCode removeContext(const std::string &token);
    ErrorCode isTokenOK(const std::string &token);
    std::string genURL(const std::string &token, const std::string &itemKey);
    ErrorCode checkExpireContext(void);
    void showInfo(void);

private:
    std::priority_queue<TokenContextPtr > mContextQueue;
    std::map<std::string, TokenContextPtr > mContextDB;
    std::string mHost;
    boost::mutex mMutex;
};

}}
#endif
