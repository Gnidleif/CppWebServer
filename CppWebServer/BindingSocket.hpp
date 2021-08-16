#pragma once

#include "SimpleSocket.hpp"

namespace CWS
{
  class BindingSocket : public SimpleSocket 
  {
  public:
    // Constructor
    BindingSocket(const char* ip_address, int port, int domain, int service, int protocol);
    // Implementation of connect_to_network first declared in SimpleSocket
    int connect_to_network(int socket, struct sockaddr_in address);

  private:
    int _connection;
  };
}