#pragma once
#include "SimpleSocket.hpp"

CWS::SimpleSocket::SimpleSocket(const char* ip_address, int port, int domain, int service, int protocol)
{
  if ((this->_socket = socket(domain, service, protocol)) == INVALID_SOCKET)
  {
    WSAData wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsOk;
    if ((wsOk = WSAStartup(ver, &wsData)) != 0)
    {
      perror("Failed to initialize WinSock...");
      exit(EXIT_FAILURE);
    }

    if ((this->_socket = socket(domain, service, protocol)) == INVALID_SOCKET)
    {
      perror("Failed to initialize socket... ");
      exit(EXIT_FAILURE);
    }
  }

  this->_address.sin_family = domain;
  this->_address.sin_port = htons(port);
  inet_pton(domain, ip_address, &this->_address.sin_addr);
}

void CWS::SimpleSocket::test_socket(int socket)
{
  if (socket == SOCKET_ERROR) 
  {
    perror("Socket error... ");
    exit(EXIT_FAILURE);
  }
}

struct sockaddr_in CWS::SimpleSocket::get_address() 
{
  return this->_address;
}

int CWS::SimpleSocket::get_socket()
{
  return this->_socket;
}