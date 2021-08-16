#pragma once
#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <WinSock2.h>

namespace CWS
{
  class SimpleSocket
  {
  public:
    // Constructor
    SimpleSocket(int domain, int service, int protocol, int port, u_long itf);
    // Virtual function to connect to a network
    virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
    // Function to test sockets and connections
    void test_connection(int item_to_test);

    // Getter functions
    struct sockaddr_in get_address();
    int get_sock();
    int get_connection();

    // Setter functions
    void set_connection(int conn);

  private:
    struct sockaddr_in address;
    int sock;
    int connection;
  };
}

#endif