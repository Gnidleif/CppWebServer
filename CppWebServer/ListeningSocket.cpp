#pragma once
#include "ListeningSocket.hpp"

CWS::ListeningSocket::ListeningSocket(const char* ip_address, int port, int domain, int service, int protocol, int backlog)
  : BindingSocket(ip_address, port, domain, service, protocol)
{
  test_socket(start_listening(this->get_socket(), backlog));

  FD_ZERO(&this->_master);
  FD_SET(this->get_socket(), &this->_master);
}

int CWS::ListeningSocket::start_listening(int socket, int backlog)
{
  return listen(socket, backlog);
}

int CWS::ListeningSocket::run()
{
  bool running = true;
  while (running)
  {
    fd_set copy = this->_master;
    int socket_count = select(0, &copy, nullptr, nullptr, nullptr);

    for (int i = 0; i < socket_count; i++)
    {
      SOCKET socket = copy.fd_array[i];
      if (socket == this->get_socket())
      {
        SOCKET client = accept(this->get_socket(), nullptr, nullptr);
        FD_SET(client, &this->_master);
      }
      else
      {
        int bytesIn;
        char buf[4096];
        ZeroMemory(buf, 4096);

        if ((bytesIn = recv(socket, buf, 4096, 0)) <= 0) 
        {
          closesocket(socket);
          FD_CLR(socket, &this->_master);
        }
      }
    }
  }

  FD_CLR(this->get_socket(), &this->_master);
  closesocket(this->get_socket());

  while (this->_master.fd_count > 0)
  {
    SOCKET socket = this->_master.fd_array[0];
    FD_CLR(socket, &this->_master);
    closesocket(socket);
  }

  WSACleanup();

  return 0;
}