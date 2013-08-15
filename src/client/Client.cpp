#include <iostream>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include "Client.hpp"

namespace asio = boost::asio;
using boost::asio::ip::tcp;

namespace {

std::string getMessage() {
  std::string message;
  std::getline(std::cin, message);
  message += '\n';
  return message;
}

}


void Client::run()
{
  try {
    repeatedlySendMessages();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

void Client::connect(const std::string& host, const std::string& service) {
  tcp::resolver::iterator address = resolve(host, service);
  asio::connect(socket_, address);
  std::cout << "Connected to server!" << std::endl;
}

tcp::resolver::iterator Client::resolve(const std::string& host, const std::string& service) {
  tcp::resolver resolver(io_service_);
  tcp::resolver::query query(host, service);
  return resolver.resolve(query);
}

void Client::repeatedlySendMessages() {
  while(true) {
    std::string message = ::getMessage();
    sendMessage(message);
  }
}

void Client::sendMessage(const std::string& message) {
  socket_.write_some( asio::buffer(message.c_str(), message.size()) );
}

