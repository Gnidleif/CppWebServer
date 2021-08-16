#include "ListeningSocket.hpp"

int main() {
  //WSAData wsData;
  //WORD ver = MAKEWORD(2, 2);
  //int wsOk, sock, port = 8080;
  //const char* ip_address = "0.0.0.0";
  //sockaddr_in hint;
  //fd_set master;

  //if ((wsOk = WSAStartup(ver, &wsData)) != 0)
  //{
  //  perror("Failed to initialize WinSock...");
  //  exit(EXIT_FAILURE);
  //}

  //if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
  //{
  //  perror("Failed to initialize socket, error: " + WSAGetLastError());
  //  exit(EXIT_FAILURE);
  //}

  //hint.sin_family = AF_INET;
  //hint.sin_port = htons(port);
  //inet_pton(AF_INET, ip_address, &hint.sin_addr);

  //if (bind(sock, (sockaddr*)&hint, sizeof(hint)) == SOCKET_ERROR) 
  //{
  //  perror("Failed to bind socket, error: " + WSAGetLastError());
  //  exit(EXIT_FAILURE);
  //}

  //if (listen(sock, SOMAXCONN) == SOCKET_ERROR)
  //{
  //  perror("Failed to bind socket, erorr: " + WSAGetLastError());
  //  exit(EXIT_FAILURE);
  //}

  //FD_ZERO(&master);
  //FD_SET(sock, &master);

  CWS::ListeningSocket ls = CWS::ListeningSocket("0.0.0.0", 8081, AF_INET, SOCK_STREAM, IPPROTO_TCP, SOMAXCONN);

  return 0;
}