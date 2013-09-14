#ifndef REMOTE_MESSAGE_HPP_
#define REMOTE_MESSAGE_HPP_

#include <boost/asio.hpp>


namespace remote {


class Message {
public:
  virtual ~Message() { };
  virtual boost::asio::const_buffer serialize() const = 0;
  virtual int size() const = 0;
};


} //remote

#endif