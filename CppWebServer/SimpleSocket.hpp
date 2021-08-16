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
    // Check socket state and exit on fail
    void test_socket(int socket);
    // Virtual declaration of connect_to_network
    virtual int connect_to_network(int socket, struct sockaddr_in address) = 0;

    // Getter functions
    struct sockaddr_in get_address();
    int get_socket();

  private:
    struct sockaddr_in _address;
    int _socket;
  };
}