#ifndef REMOTE_CLIENT_HPP_
#define REMOTE_CLIENT_HPP_

#include <boost/asio.hpp>

class Client {
public:
  Client()
    : socket_(io_service_) 
  { }
  void connect(const std::string& host, const std::string& service);
  void run();
private:
  boost::asio::ip::tcp::resolver::iterator resolve( const std::string& host, 
                                                    const std::string& service );
  void repeatedlySendMessages();
  void sendMessage(const std::string& message);

private:
  boost::asio::io_service io_service_;
  boost::asio::ip::tcp::socket socket_;
};

#endif