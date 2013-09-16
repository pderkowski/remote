// Copyright 2013 <Piotr Derkowski>

#ifndef REMOTE_IMESSAGE_HPP_
#define REMOTE_IMESSAGE_HPP_

#include "boost/asio.hpp"


namespace remote {

namespace message {


class IMessage {
public:
  virtual ~IMessage() { }
  virtual boost::asio::const_buffer serialize() const = 0;
  virtual int size() const = 0;
};


}  // namespace message

}  // namespace remote

#endif
