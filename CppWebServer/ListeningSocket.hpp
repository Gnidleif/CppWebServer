#pragma once
#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>

#include "BindingSocket.hpp"

namespace CWS
{
  class ListeningSocket : BindingSocket
  {
  public:
    // Constructor
    ListeningSocket(int domain, int service, int protocol, int port, u_long itf, int backlog);
    void start_listening();


  private:
    int backlog;
    int listening;
  };
}

#endif