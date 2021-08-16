#pragma once

#include "BindingSocket.hpp"

namespace CWS
{
  class ListeningSocket : public BindingSocket
  {
  public:
    // Constructor
    ListeningSocket(const char* ip_address, int port, int domain, int service, int protocol, int backlog);
    // Start listening on the passed socket
    int start_listening(int socket, int backlog);
    int run();

  private:
    fd_set _master;
  };
}