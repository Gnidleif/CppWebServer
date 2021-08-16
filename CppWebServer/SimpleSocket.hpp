#pragma once

#include <cassert>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

namespace CWS
{
  class SimpleSocket
  {
  public:
    // Constructor
    SimpleSocket(const char* ip_address, const char* port, int family, int socktype, int protocol, int flags);
    // Check socket state and exit on fail
    void test_socket(int socket);
    // Virtual declaration of connect_to_network
    virtual int connect_to_network(int socket, addrinfo* address) = 0;

    // Getter functions
    addrinfo* get_address();
    int get_socket();

  private:
    addrinfo* _address;
    int _socket;
  };
}