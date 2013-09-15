// Copyright 2013 <Piotr Derkowski>

#include <iostream>
#include <algorithm>
#include "utils/make_unique.hpp"
#include "message/TextMessageFeeder.hpp"
#include "Client.hpp"

using utils::make_unique;


int main() {
  auto feeder = make_unique<remote::TextMessageFeeder>(std::cin);
  remote::Client client(std::move(feeder));
  client.connect("localhost", "12345");
  client.run();
  return 0;
}
