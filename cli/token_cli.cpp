/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <iostream>

#include <protocol/TBinaryProtocol.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>

#include "TokenService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace boost;

int main(int argc, char** argv)
{
    shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    tw::maple::generated::TokenServiceClient client(protocol);

    try {
        char buf[256];
        string token;

        transport->open();
        for(int i=0; i<10; i++) {
            sprintf(buf, "user%d", i);
            string t1(buf);
            string ret;

            client.getToken(ret, t1, time(NULL) + i);
            if(i == 3) {
                token = ret;
                printf("token: %s\n", token.c_str());
            }
        }
        string url1, url2;
        client.getURL(url1, token, "", 0);   // for persistent url
        printf("url: %s\n", url1.c_str());

        client.getURL(url2, token, "itemKey", 1); // for expire url
        printf("url: %s\n", url2.c_str());

        printf("removing token: %s\n", token.c_str());
        client.removeToken(token);
        client.checkURL(url1);
        client.checkURL(url2);

//        client.checkToken(token);

        transport->close();
    } catch (tw::maple::generated::NotFoundException &nfe) {
        printf("ERROR: %s\n", nfe.why.c_str());
    } catch (TException &tx) {
        printf("ERROR: %s\n", tx.what());
    }

    return 0;
}
