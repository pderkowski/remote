// Copyright 2013 <Piotr Derkowski>

#include "Server.hpp"

int main() {
  remote::Server server;
  server.listen(12345);
  return 0;
}

