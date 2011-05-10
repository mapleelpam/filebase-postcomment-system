
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>

#include <concurrency/ThreadManager.h>
#include <concurrency/PosixThreadFactory.h>
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <server/TThreadPoolServer.h>
#include <server/TThreadedServer.h>
#include <transport/TServerSocket.h>
#include <transport/TTransportUtils.h>

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "gen-cpp/PostSystem.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using namespace boost;

using namespace tw::maple::generated;

class PostSystemHandler : virtual public PostSystemIf {
 public:
  PostSystemHandler() {
    // Your initialization goes here
  }

  void newPost(UUID& postid, const std::string& user, const std::string& content) {
      printf("newPost\n");
      {
          boost::uuids::uuid tag = boost::uuids::random_generator()();
          std::stringstream ss;
          ss << tag;
          ss >> postid;
      }
      {
            boost::filesystem::ofstream ofs(postid+".txt");
            ofs << content;
      }
  }

  bool deletePost(const UUID& post_id) {
    // Your implementation goes here
    printf("deletePost\n");
  }

  void newComment(UUID& _return, const UUID& post_id, const std::string& comment) {
    // Your implementation goes here
    printf("newComment\n");
  }

  bool rmComment(const UUID& post_id, const UUID& comment) {
    // Your implementation goes here
    printf("rmComment\n");
  }

  void getContent(std::string& _return, const UUID& post_id) {
    // Your implementation goes here
    printf("getContent\n");
  }
  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }


};

int main(int argc, char **argv) {

  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  shared_ptr<PostSystemHandler> handler(new PostSystemHandler());
  shared_ptr<TProcessor> processor(new PostSystemProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(9090));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());

  TSimpleServer server(processor,
                       serverTransport,
                       transportFactory,
                       protocolFactory);


  /**
   * Or you could do one of these

  shared_ptr<ThreadManager> threadManager =
    ThreadManager::newSimpleThreadManager(workerCount);
  shared_ptr<PosixThreadFactory> threadFactory =
    shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();
  TThreadPoolServer server(processor,
                           serverTransport,
                           transportFactory,
                           protocolFactory,
                           threadManager);

  TThreadedServer server(processor,
                         serverTransport,
                         transportFactory,
                         protocolFactory);

  */

  printf("Starting the server...\n");
  server.serve();
  printf("done.\n");
  return 0;
}
