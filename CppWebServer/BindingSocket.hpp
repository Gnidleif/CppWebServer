#pragma once

#include "SimpleSocket.hpp"

namespace CWS
{
  class BindingSocket : public SimpleSocket 
  {
  public:
    BindingSocket(const char* ip_address, int port, int domain, int service, int protocol);
    int connect_to_network();

  private:
    int _connection;
  };
}