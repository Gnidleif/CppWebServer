#pragma once
#include "ListeningSocket.hpp"

CWS::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long itf, int backlog)
  : BindingSocket(domain, service, protocol, port, itf)
{
  this->backlog = backlog;
  start_listening();
  test_connection(this->listening);
}

void CWS::ListeningSocket::start_listening() 
{
  // not sure if supposed to be get_sock()
  this->listening = listen(get_connection(), this->backlog);
}