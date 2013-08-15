#include <iostream>
#include <exception>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string getMessageFromBuffer(boost::asio::streambuf& buffer) {
  std::istream inputStream(&buffer);
  std::string message;
  inputStream >> message;
  return message;
}

void echo(tcp::socket& socket)
{
  boost::asio::streambuf inputBuffer;

  boost::asio::read_until(socket, inputBuffer, '\n');
  std::cout << getMessageFromBuffer(inputBuffer) << std::endl;
}

int main() {
  try
  {
    boost::asio::io_service io_service;

    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 12345));

    tcp::socket socket(io_service);
    acceptor.accept(socket);
    while(true) {
      echo(socket);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}



