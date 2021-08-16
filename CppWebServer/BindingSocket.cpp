#pragma once
#include "BindingSocket.hpp"

CWS::BindingSocket::BindingSocket(const char* ip_address, int port, int domain, int service, int protocol)
  : SimpleSocket(ip_address, port, domain, service, protocol)
{
  test_socket(connect_to_network(this->get_socket(), this->get_address()));
}

int CWS::BindingSocket::connect_to_network(int socket, struct sockaddr_in address)
{
  return bind(socket, (struct sockaddr*)&address, sizeof(address));
}