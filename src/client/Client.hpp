// Copyright 2013 <Piotr Derkowski>

#ifndef CLIENT_CLIENT_HPP_
#define CLIENT_CLIENT_HPP_

#include <string>
#include <iostream>
#include "boost/asio.hpp"
#include "messenger/Messenger.hpp"

namespace client {


template <class Message>
class Client : public messenger::Messenger<Message> {
public:
  void connect(const std::string& host, const std::string& service) {
    auto address = resolve(host, service);
    boost::asio::connect(this->socket_, address);
    std::cout << "Connected to " + host + ":" + service + "!" << std::endl;
  }

  virtual ~Client() { }

private:
  boost::asio::ip::tcp::resolver::iterator resolve(const std::string& host,
                                                   const std::string& service) {
    boost::asio::ip::tcp::resolver resolver(this->io_service_);
    boost::asio::ip::tcp::resolver::query query(host, service);
    return resolver.resolve(query);
  }
};


}


#endif  // CLIENT_CLIENT_HPP_
