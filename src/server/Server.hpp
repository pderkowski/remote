// Copyright 2013 <Piotr Derkowski>

#ifndef REMOTE_SERVER_HPP_
#define REMOTE_SERVER_HPP_

#include "boost/asio.hpp"
#include "boost/function.hpp"
#include "boost/noncopyable.hpp"


namespace remote {


class Server : boost::noncopyable {
public:
  Server()
    : socket_(io_service_)
  { }

  void listen(int port);
private:
  void acceptConnection(int port);
  void processRequests();
  void echo();

  boost::asio::io_service io_service_;
  boost::asio::ip::tcp::socket socket_;
};


}  // namespace remote

#endif
