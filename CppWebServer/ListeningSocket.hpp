#pragma once

#include "BindingSocket.hpp"

namespace CWS
{
  class ListeningSocket : public BindingSocket
  {
  public:
    // Constructor
    ListeningSocket(const char* ip_address, const char* port, int family, int socktype, int protocol, int flags, int backlog);
    // Start listening on the passed socket
    int start_listening(int socket, int backlog);
    virtual int run() = 0;
  };
}