#include <iostream>

#include "ListeningSocket.hpp"

int main() {
  std::cout << "Starting..." << std::endl;
  std::cout << "Binding socket..." << std::endl;
  CWS::BindingSocket bs = CWS::BindingSocket(AF_INET, SOCK_STREAM, 0, 8081, INADDR_ANY);
  std::cout << "Listening socket..." << std::endl;
  CWS::ListeningSocket ls = CWS::ListeningSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);
  std::cout << "Success!" << std::endl;

  return 0;
}