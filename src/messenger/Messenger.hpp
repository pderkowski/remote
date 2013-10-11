// Copyright 2013 <Piotr Derkowski>

#ifndef MESSENGER_MESSENGER_HPP_
#define MESSENGER_MESSENGER_HPP_

#include <iostream>
#include <thread>
#include <functional>
#include <stdexcept>
#include "boost/asio/streambuf.hpp"
#include "boost/noncopyable.hpp"
#include "boost/asio.hpp"

namespace messenger {


template <class Message>
class Messenger : public boost::noncopyable {
public:
  Messenger()
      : io_service_(), socket_(io_service_)
  { }

  void send(const Message& message) {
    boost::asio::streambuf bufferedMessage;
    std::ostream streamedMessage(&bufferedMessage);
    streamedMessage << message << '\n';
    boost::asio::write(socket_, bufferedMessage, boost::asio::transfer_all());
  }

  Message receive() {
    boost::asio::streambuf bufferedMessage;
    boost::asio::read_until(socket_, bufferedMessage, '\n');

    std::istream streamedMessage(&bufferedMessage);
    Message message;
    streamedMessage >> message;
    return message;
  }

  void sendMessages(std::istream& streamOfMessagesToSend) {
    std::cout << "Starting sending messages." << std::endl;
    while (streamOfMessagesToSend.good()) {
      Message message;
      streamOfMessagesToSend >> message;
      send(message);
    }
  }

  void receiveMessages(std::ostream& streamForReceivedMessages) {
    std::cout << "Starting receiving messages." << std::endl;
    Message message;
    while (true) {
      message = receive();
      streamForReceivedMessages << message << std::endl;
    }
  }

  void run(std::istream& streamOfMessagesToSend, std::ostream& streamForReceivedMessages) {
    try {
      std::thread sending(std::bind(&messenger::Messenger<Message>::sendMessages, this, 
        std::ref(streamOfMessagesToSend)));
      std::thread receiving(std::bind(&messenger::Messenger<Message>::receiveMessages, this, 
        std::ref(streamForReceivedMessages)));

      sending.join();
      receiving.join();
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }

  virtual ~Messenger() { }

protected:
  boost::asio::io_service io_service_;
  boost::asio::ip::tcp::socket socket_;
};


}  // namespace messenger

#endif  // MESSENGER_MESSENGER_HPP_
