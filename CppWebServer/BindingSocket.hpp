#pragma once
#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>

#include "SimpleSocket.hpp"

namespace CWS
{
  class BindingSocket: public SimpleSocket
  {
  public:
    // Constructor
    BindingSocket(int domain, int service, int protocol, int port, u_long itf);
    // Implementation of virtual function used to connect to network
    int connect_to_network(int sock, struct sockaddr_in address);
  };
}

#endif