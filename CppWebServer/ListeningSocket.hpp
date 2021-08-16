#pragma once

#include "BindingSocket.hpp"

namespace CWS
{
  class ListeningSocket : public BindingSocket
  {
  public:
    // Constructor
    ListeningSocket(const char* ip_address, int port, int domain, int service, int protocol, int backlog);
    // Override of connect_to_network first implemented in BindingSocket
    int connect_to_network();
    // Implementation of run first declared in SimpleSocket
    int run();

  private:
    int _listening;
    int _backlog;
    fd_set _master;
  };
}