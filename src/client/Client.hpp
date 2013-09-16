// Copyright 2013 <Piotr Derkowski>

#ifndef REMOTE_CLIENT_HPP_
#define REMOTE_CLIENT_HPP_

#include <string>
#include <memory>
#include "boost/asio.hpp"
#include "boost/noncopyable.hpp"
#include "messenger/message/IMessageFeeder.hpp"

class Message;


namespace remote {


class Client : boost::noncopyable {
public:
  explicit Client(std::unique_ptr<message::IMessageFeeder> feeder);
  void connect(const std::string& host, const std::string& service);
  void run();

private:
  boost::asio::ip::tcp::resolver::iterator resolve(const std::string& host,
                                                   const std::string& service);
  void sendMessages();
  void doSendMessage(const message::IMessage& message);

private:
  boost::asio::io_service io_service_;
  boost::asio::ip::tcp::socket socket_;
  std::unique_ptr<message::IMessageFeeder> feeder_;
};


}  // namespace remote

#endif
