#pragma once
#include "BindingSocket.hpp"

CWS::BindingSocket::BindingSocket(const char* ip_address, int port, int domain, int service, int protocol)
  : SimpleSocket(ip_address, port, domain, service, protocol)
{
  this->_connection = connect_to_network();
  test_socket(this->_connection);
}

int CWS::BindingSocket::connect_to_network()
{
  int sock = this->get_socket();
  struct sockaddr_in address = this->get_address();
  return bind(sock, (struct sockaddr*)&address, sizeof(address));
}