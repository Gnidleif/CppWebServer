#include "HttpServer.hpp"

int main() {
  CWS::HttpServer server = CWS::HttpServer("127.0.0.1", "8081");
  server.run();

  return 0;
}