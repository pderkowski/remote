// Copyright 2013 <Piotr Derkowski>

#include <iostream>
#include <exception>
#include <string>
#include "boost/asio.hpp"
#include "Server.hpp"

using boost::asio::ip::tcp;

namespace {

std::string getMessageFromBuffer(boost::asio::streambuf& buffer) {  // NOLINT(runtime/references)
  std::istream inputStream(&buffer);
  std::string message;
  std::getline(inputStream, message);
  return message;
}

}


namespace remote {


void Server::listen(int port) {
  try {
    acceptConnection(port);
    processRequests();
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void Server::acceptConnection(int port) {
  tcp::acceptor acceptor(io_service_, tcp::endpoint(tcp::v4(), port));
  acceptor.accept(socket_);
}

void Server::processRequests() {
  while (true) {
    echo();
  }
}

void Server::echo() {
  boost::asio::streambuf inputBuffer;

  boost::asio::read_until(socket_, inputBuffer, '\n');
  std::cout << ::getMessageFromBuffer(inputBuffer) << std::endl;
}


}  // namespace remote










