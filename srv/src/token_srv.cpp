// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "gen-cpp/TokenService.h"
#include "service/token/tokenmanager.h"

#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>
#include <boost/thread.hpp>
#include <time.h>
#include <boost/shared_ptr.hpp>

struct ExpiredTokenCleanupThread
{
    void operator()()
    {
        int sleep_time = 3;

        while(1) {
            printf("clean context thread sleep_time = %d\n", sleep_time);
            boost::this_thread::sleep(boost::posix_time::seconds(sleep_time));
            int32_t next_sleep = service::token::TokenManager::instance()->checkExpireContext();

            sleep_time = (next_sleep > 0) ? next_sleep : 3;
        }
    };
};

class TokenServiceHandler : virtual public tw::maple::generated::TokenServiceIf
{
public:
    TokenServiceHandler() {
        // Your initialization goes here
    }

    void getToken(std::string& _return, const std::string& userId, const int32_t default_expire_time)
    {
        std::string token = service::token::TokenManager::instance()->genToken();
        std::string key = userId + "_" + token;
        service::token::ContextPtr context(new service::token::Context(userId, token, default_expire_time));

        service::token::TokenManager::instance()->insertToken(context);
        _return = key;
//        printf("expireTime: %d, token: %s, userId: %s\n", default_expire_time, token.c_str(), userId.c_str());
    }

    void removeToken(const std::string& token)
    {
        printf("removeToken\n");
        service::token::TokenManager::ErrorCode rc = service::token::TokenManager::instance()->removeToken(token);

        if(rc == service::token::TokenManager::CANT_FOUND_TOKEN) {
            tw::maple::generated::NotFoundException nfe;

            nfe.why = "Token Not Found";
            throw nfe;
        }
    }

    void checkToken(const std::string& token)
    {
        printf("checkToken\n");
        service::token::TokenManager::ErrorCode rc = service::token::TokenManager::instance()->isTokenOK(token);

        if(rc == service::token::TokenManager::CANT_FOUND_TOKEN) {
        	tw::maple::generated::NotFoundException nfe;

            nfe.why = "Token Not Found";
            throw nfe;
        }
    }

    void getURL(std::string& _return, const std::string& token,
            const std::string& itemKey, const int32_t expireTime)
    {
        printf("getURL\n");
        checkToken(token);

        _return  = service::token::TokenManager::instance()->genURL(token, itemKey, expireTime);
    }

    void checkURL(const std::string &url)
    {
        printf("checkURL\n");
        if(service::token::TokenManager::instance()->checkURL(url) != service::token::TokenManager::SUCCESS) {
        	tw::maple::generated::NotFoundException nfe;

            nfe.why = "URL Not Exist";
            throw nfe;
        }
    }
};

int main(int argc, char **argv)
{

	using namespace ::apache::thrift;
	using namespace ::apache::thrift::protocol;
	using namespace ::apache::thrift::transport;
	using namespace ::apache::thrift::server;


    int port = 9090;
    boost::shared_ptr<TokenServiceHandler> handler(new TokenServiceHandler());

    boost::shared_ptr<TProcessor> processor(new tw::maple::generated::TokenServiceProcessor(handler));
    boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);

    // first call of this service
    service::token::TokenManager::instance();

    // create clean expire context thread
    ExpiredTokenCleanupThread clean_context;
    boost::thread clean_thread(clean_context);
    clean_thread.detach();

    server.serve();

    return 0;
}
