#pragma once
#include "SimpleSocket.hpp"

CWS::SimpleSocket::SimpleSocket(const char* ip_address, const char* port, int family, int socktype, int protocol, int flags)
{
  // If socket initialization fails it probably means that WinSock isn't initialized yet
  if ((this->_socket = socket(family, socktype, protocol)) == INVALID_SOCKET)
  {
    WSAData wsData;
    assert(WSAStartup(MAKEWORD(2, 2), &wsData) == 0);
    assert((this->_socket = socket(family, socktype, protocol)) != INVALID_SOCKET);
  }

  addrinfo hints;
  ZeroMemory(&hints, sizeof(hints));

  hints.ai_family = family;
  hints.ai_socktype = socktype;
  hints.ai_protocol = protocol;
  hints.ai_flags = flags;

  this->_address = nullptr;

  assert(getaddrinfo(ip_address, port, &hints, &this->_address) == 0);
}

CWS::SimpleSocket::~SimpleSocket()
{
  freeaddrinfo(this->_address);
}

void CWS::SimpleSocket::test_socket(int socket)
{
  assert(socket != SOCKET_ERROR);
}

addrinfo* CWS::SimpleSocket::get_address()
{
  return this->_address;
}

int CWS::SimpleSocket::get_socket()
{
  return this->_socket;
}