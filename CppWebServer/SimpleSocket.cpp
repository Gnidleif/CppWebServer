#pragma once
#include "SimpleSocket.hpp"

// Default constructor
CWS::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long itf)
{
  // Define address structure
  this->address.sin_family = domain;
  this->address.sin_port = htons(port);
  this->address.sin_addr.S_un.S_addr = htonl(itf);

  // Establish socket
  this->sock = socket(domain, service, protocol);
  test_connection(sock);
};

// Test connection virtual function
void CWS::SimpleSocket::test_connection(int item_to_test)
{
  if (item_to_test < 0)
  {
    perror("Failed to connect...");
    exit(EXIT_FAILURE);
  }
}

// Getter functions

struct sockaddr_in CWS::SimpleSocket::get_address()
{
  return this->address;
}

int CWS::SimpleSocket::get_sock()
{
  return this->sock;
}

int CWS::SimpleSocket::get_connection()
{
  return this->connection;
}

void CWS::SimpleSocket::set_connection(int conn)
{
  this->connection = conn;
}