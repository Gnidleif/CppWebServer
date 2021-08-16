#pragma once
#include "ListeningSocket.hpp"

CWS::ListeningSocket::ListeningSocket(const char* ip_address, const char* port, int family, int socktype, int protocol, int flags, int backlog)
  : BindingSocket(ip_address, port, family, socktype, protocol, flags)
{
  test_socket(start_listening(get_socket(), backlog));
}

int CWS::ListeningSocket::start_listening(int socket, int backlog)
{
  return listen(socket, backlog);
}