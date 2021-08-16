#pragma once
#include "BindingSocket.hpp"

// Constructor
CWS::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long itf)
  : SimpleSocket(domain, service, protocol, port, itf)
{
  // Establish network connection
  set_connection(connect_to_network(get_sock(), get_address()));
  test_connection(get_connection());
}

// Implementation of connect_to_network virtual function
int CWS::BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
  return bind(sock, (struct sockaddr*)&address, sizeof(address));
}