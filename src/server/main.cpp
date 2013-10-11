// Copyright 2013 <Piotr Derkowski>

#include "Server.hpp"
#include "messenger/TextMessage.hpp"

int main() {
  server::Server<messenger::TextMessage> server;
  server.listen(12345);
  return 0;
}

