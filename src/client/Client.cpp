#include <iostream>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <message/MessageFeeder.hpp>
#include "Client.hpp"
#include "message/Message.hpp"

namespace asio = boost::asio;
using boost::asio::ip::tcp;


remote::Client::Client(MessageFeeder& feeder)
  : socket_(io_service_), feeder_(feeder) 
{ }

void remote::Client::run()
{
  try {
    sendMessages();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}

void remote::Client::connect(const std::string& host, const std::string& service) {
  tcp::resolver::iterator address = resolve(host, service);
  asio::connect(socket_, address);
  std::cout << "Connected to " + host + ":" + service + "!" << std::endl;
}

tcp::resolver::iterator remote::Client::resolve(const std::string& host, 
                                                const std::string& service) {
  tcp::resolver resolver(io_service_);
  tcp::resolver::query query(host, service);
  return resolver.resolve(query);
}

void remote::Client::sendMessages() {
  while( !feeder_.hasStoppedFeeding() ) {
    std::unique_ptr<remote::Message> message = feeder_.getMessage();
    doSendMessage(*message);
  }
}

void remote::Client::doSendMessage(const remote::Message& message) {
  socket_.write_some( boost::asio::buffer(message.serialize()) );
}

