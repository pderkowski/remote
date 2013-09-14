#ifndef REMOTE_CLIENT_HPP_
#define REMOTE_CLIENT_HPP_

#include <boost/asio.hpp>
#include <message/MessageFeeder.hpp>

class Message;


namespace remote {


class Client {
public:
  Client(MessageFeeder& feeder);
  void connect(const std::string& host, const std::string& service);
  void run();
private:
  boost::asio::ip::tcp::resolver::iterator resolve( const std::string& host, 
                                                    const std::string& service );
  void sendMessages();
  void doSendMessage(const remote::Message& message);

private:
  boost::asio::io_service io_service_;
  boost::asio::ip::tcp::socket socket_;
  remote::MessageFeeder& feeder_;
};


} //remote

#endif