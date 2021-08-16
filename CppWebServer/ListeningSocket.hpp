#pragma once
#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include "BindingSocket.hpp"

namespace CWS
{
  class ListeningSocket : public BindingSocket
  {
  public:
    // Constructor
    ListeningSocket(int domain, int service, int protocol, int port, u_long itf, int backlog);
    // Listening function
    void start_listening();

    // Getter functions
    int get_listening();
    int get_backlog();

  private:
    int listening;
    int backlog;
  };
}

#endif