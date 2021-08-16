#pragma once

#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

namespace CWS
{
  class SimpleSocket
  {
  public:
    // Constructor
    SimpleSocket(const char* ip_address, int port, int domain, int service, int protocol);
    void test_socket(int socket);
    virtual int connect_to_network() = 0;
    virtual int run() = 0;

    struct sockaddr_in get_address();
    int get_socket();

  private:
    struct sockaddr_in _address;
    int _socket;
  };
}