// Copyright 2013 <Piotr Derkowski>

#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include "boost/array.hpp"
#include "boost/bind.hpp"
#include "boost/asio.hpp"
#include "messenger/message/MessageFeeder.hpp"
#include "messenger/message/IMessage.hpp"
#include "Client.hpp"

namespace asio = boost::asio;
using boost::asio::ip::tcp;

namespace remote {


Client::Client(std::unique_ptr<MessageFeeder> feeder)
    : socket_(io_service_), feeder_(feeder) {
  if (!feeder_) {
    throw std::invalid_argument("Null pointer to feeder.");
  }
}

void Client::run() {
  try {
    sendMessages();
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void Client::connect(const std::string& host, const std::string& service) {
  tcp::resolver::iterator address = resolve(host, service);
  asio::connect(socket_, address);
  std::cout << "Connected to " + host + ":" + service + "!" << std::endl;
}

tcp::resolver::iterator Client::resolve(const std::string& host,
                                        const std::string& service) {
  tcp::resolver resolver(io_service_);
  tcp::resolver::query query(host, service);
  return resolver.resolve(query);
}

void Client::sendMessages() {
  while ( !feeder_->hasStoppedFeeding() ) {
    std::unique_ptr<Message> message = feeder_->getMessage();
    doSendMessage(*message);
  }
}

void Client::doSendMessage(const Message& message) {
  socket_.write_some(boost::asio::buffer(message.serialize()));
}


}  // namespace remote

