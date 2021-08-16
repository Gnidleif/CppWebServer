#include "ListeningSocket.hpp"

int main() {
  CWS::ListeningSocket ls = CWS::ListeningSocket("127.0.0.1", 8081, AF_INET, SOCK_STREAM, IPPROTO_TCP, SOMAXCONN);
  ls.run();

  return 0;
}