#include <iostream>
#include <exception>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
  try
  {
    boost::asio::io_service io_service;

    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 12345));

    for (;;)
    {
      tcp::socket socket(io_service);
      acceptor.accept(socket);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "Hello world!" << std::endl;
  return 0;
}




