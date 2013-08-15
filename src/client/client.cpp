#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using boost::asio::ip::tcp;

void sendHello(tcp::socket& socket) {
  std::string hello = "Hello!\n";
  boost::system::error_code error;
  socket.write_some( boost::asio::buffer(hello.c_str(), hello.size()), error );
}

void repeatedlySendHelloMessages(tcp::socket& socket, boost::asio::io_service& io) {
  while(true) {
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(1));
    timer.wait();
    sendHello(socket);
    std::cout << "Sent" << std::endl;
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

    repeatedlySendHelloMessages(socket, io_service);
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
