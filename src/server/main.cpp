#include "Server.hpp"

int main() {
  Server server;
  server.listen(12345);
  return 0;
}