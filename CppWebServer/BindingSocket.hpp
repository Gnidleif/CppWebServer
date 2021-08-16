#pragma once

#include "SimpleSocket.hpp"

namespace CWS
{
  class BindingSocket : public SimpleSocket 
  {
  public:
    // Constructor
    BindingSocket(const char* ip_address, const char* port, int family, int socktype, int protocol, int flags);
    // Implementation of connect_to_network first declared in SimpleSocket
    int connect_to_network(int socket, addrinfo* address);
  };
}