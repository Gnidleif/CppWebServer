#pragma once

#include "ListeningSocket.hpp"

#include <fstream>
#include <string>

namespace CWS
{
  class HttpServer : public ListeningSocket
  {
  public:
    HttpServer(const char* ip_address, const char* port);
    int run();

  private:
    fd_set _master;

    std::string read_file(std::string file_name);
  };
}