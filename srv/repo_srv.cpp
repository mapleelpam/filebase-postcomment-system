// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "RepositoryService.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

#include "error.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace tw::maple::generated;
using namespace tw::test;

GlobalManager *gmanager;

class RepositoryServiceHandler : virtual public RepositoryServiceIf {
public:
    RepositoryServiceHandler() {
        // Your initialization goes here
    }

    void userLogin(const std::string& repo_name, const std::string& username, const std::string& password) {
        // Your implementation goes here
        printf("userLogin\n");
        shared_ptr<Account> account = g_manager->accountAPI();

        ErrorCode rc = account->checkUser(username, password);

        if(rc != SUCCESS) {
            AuthenticationException authenx;

            authenx.why = "login fail";
            throw authenx;
        }
        rc = account->checkRepo(repo_name);
        if(rc != SUCCESS) {
            NotFoundException ne;

            throw ne;
        }
    }

    int8_t getUserPermissionMask() {
        // Your implementation goes here
        printf("getUserPermissionMask\n");
    }

    void addTextData(UUID& _return, const std::string& content, const std::string& categories, const int32_t default_expire_time) {
        // Your implementation goes here
        printf("addTextData\n");
    }

    void modifyTextData(const std::string& repo_name, const UUID& instance_id, const std::string& new_content) {
        // Your implementation goes here
        printf("modifyTextData\n");
    }

    void getTextURL(URL& _return, const std::string& repo_name, const UUID& instance_id) {
        // Your implementation goes here
        printf("getTextURL\n");
    }

};

int main(int argc, char **argv) {
    int port = 9090;
    shared_ptr<RepositoryServiceHandler> handler(new RepositoryServiceHandler());
    shared_ptr<TProcessor> processor(new RepositoryServiceProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);

    gmanager = new GlobalManager();
    server.serve();
    return 0;
}

