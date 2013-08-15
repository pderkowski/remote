#include "Client.hpp"

int main() {
  Client client;
  client.connect("localhost", "12345");
  client.run();
  return 0;
}