#include <iostream>
#include <exception>
#include <string>
#include <boost/asio.hpp>
#include "Server.hpp"

using boost::asio::ip::tcp;

namespace {

std::string getMessageFromBuffer(boost::asio::streambuf& buffer) {
  std::istream inputStream(&buffer);
  std::string message;
  std::getline(inputStream, message);
  return message;
}

}


void remote::Server::listen(int port) {
  try
  {
    acceptConnection(port);
    processRequests();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

void remote::Server::acceptConnection(int port) {
  tcp::acceptor acceptor(io_service_, tcp::endpoint(tcp::v4(), port));
  acceptor.accept(socket_);
}

void remote::Server::processRequests() {
  while(true) {
    echo();
  }
}

void remote::Server::echo()
{
  boost::asio::streambuf inputBuffer;

  boost::asio::read_until(socket_, inputBuffer, '\n');
  std::cout << ::getMessageFromBuffer(inputBuffer) << std::endl;
}









