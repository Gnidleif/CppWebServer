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
  this->listening = listen(get_sock(), this->backlog);
}

int CWS::ListeningSocket::get_listening()
{
  return this->listening;
}

int CWS::ListeningSocket::get_backlog()
{
  return this->backlog;
}