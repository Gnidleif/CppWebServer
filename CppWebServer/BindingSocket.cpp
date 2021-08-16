#pragma once
#include "BindingSocket.hpp"

CWS::BindingSocket::BindingSocket(const char* ip_address, const char* port, int family, int socktype, int protocol, int flags)
  : SimpleSocket(ip_address, port, family, socktype, protocol, flags)
{
  test_socket(connect_to_network(get_socket(), get_address()));
}

int CWS::BindingSocket::connect_to_network(int socket, addrinfo* address)
{
  return bind(socket, address->ai_addr, (int)address->ai_addrlen);
}