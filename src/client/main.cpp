#include <iostream>
#include <message/TextMessageFeeder.hpp>
#include "Client.hpp"


int main() {
  remote::TextMessageFeeder feeder(std::cin);
  remote::Client client(feeder);
  client.connect("localhost", "12345");
  client.run();
  return 0;
}