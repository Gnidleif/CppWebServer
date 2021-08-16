#pragma once
#include "HttpServer.hpp"

using namespace std;

CWS::HttpServer::HttpServer(const char* ip_address, const char* port)
  : ListeningSocket(ip_address, port, AF_INET, SOCK_STREAM, IPPROTO_TCP, AI_PASSIVE, SOMAXCONN)
{
  FD_ZERO(&this->_master);
  FD_SET(this->get_socket(), &this->_master);
}

int CWS::HttpServer::run()
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
        // Accept new connection
        socket = accept(this->get_socket(), nullptr, nullptr);
        std::string msg = read_file("index.html");
        while (send(socket, msg.c_str(), msg.size() + 1, 0) != msg.size() + 1);
        FD_SET(socket, &this->_master);
        shutdown(socket, SD_SEND);
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

string CWS::HttpServer::read_file(string file_name)
{
  string content;
  ifstream f = ifstream(file_name);
  if (f.is_open())
  {
    string line;
    while (f.good()) 
    {
      getline(f, line);
      content += line + "\n\r";
    }
    f.close();
  }

  return content;
}