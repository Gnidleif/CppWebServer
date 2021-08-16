#pragma once
#include "ConnectingSocket.hpp"

// Constructor
CWS::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long itf)
  : SimpleSocket(domain, service, protocol, port, itf)
{
  // Establish network connection
  set_connection(connect_to_network(get_sock(), get_address()));
  test_connection(get_connection());
}

// Implementation of connect_to_network virtual function
int CWS::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
{
  return connect(sock, (struct sockaddr*)&address, sizeof(address));
}