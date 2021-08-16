#pragma once

#include "BindingSocket.hpp"

namespace CWS
{
  class ListeningSocket : public BindingSocket
  {
  public:
    ListeningSocket(const char* ip_address, int port, int domain, int service, int protocol, int backlog);
    int connect_to_network();
    int run();
    void on_client_connect(int client_socket);
    void on_client_disconnect(int client_socket);

  private:
    int _listening;
    int _backlog;
    fd_set _master;
  };
}