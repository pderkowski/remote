// Copyright 2013 <Piotr Derkowski>

#ifndef SERVER_SERVER_HPP_
#define SERVER_SERVER_HPP_

#include <iostream>
#include <exception>
#include <string>
#include "boost/asio.hpp"
#include "boost/function.hpp"
#include "boost/noncopyable.hpp"
#include "messenger/Messenger.hpp"

namespace server {


template <class Message>
class Server : public messenger::Messenger<Message> {
public:
  void listen(int port) {
    try {
      acceptConnection(port);
      this->run(std::cin, std::cout);
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }

  virtual ~Server() { }

private:
  void acceptConnection(int port) {
    using boost::asio::ip::tcp;

    tcp::acceptor acceptor(this->io_service_, tcp::endpoint(tcp::v4(), port));
    acceptor.accept(this->socket_);
    std::cout << "Accepted connection at port " << port << "." << std::endl;
  }
};


}  // namespace server

#endif  // SERVER_SERVER_HPP_
