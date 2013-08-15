#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::tcp;

std::string getMessage() {
  std::string message;
  std::getline(std::cin, message);
  message += '\n';
  return message;
}

void sendMessage(const std::string& message, tcp::socket& socket) {
  boost::system::error_code error;
  socket.write_some( boost::asio::buffer(message.c_str(), message.size()), error );
}

void repeatedlySendMessages(tcp::socket& socket, boost::asio::io_service& io) {
  while(true) {
    std::string message = getMessage();
    sendMessage(message, socket);
    std::cout << "Message sent!" << std::endl;
  }
}

int main()
{
  try {
    boost::asio::io_service io_service;

    tcp::resolver resolver(io_service);
    tcp::resolver::query query("localhost", "12345");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);

    std::cout << "Connected to server!" << std::endl;

    repeatedlySendMessages(socket, io_service);
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
