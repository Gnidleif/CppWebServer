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
    BindingSocket(int domain, int service, int protocol, int port, u_long itf);
    int connect_to_network(int sock, struct sockaddr_in address);
  };
}

#endif