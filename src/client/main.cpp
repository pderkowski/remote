// Copyright 2013 <Piotr Derkowski>

#include <iostream>
#include <algorithm>
#include "Client.hpp"
#include "messenger/TextMessage.hpp"

int main() {
  client::Client<messenger::TextMessage> client;
  client.connect("localhost", "12345");
  client.run(std::cin, std::cout);
  return 0;
}
