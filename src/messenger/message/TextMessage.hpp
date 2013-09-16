// Copyright 2013 <Piotr Derkowski>

#ifndef REMOTE_TEXTMESSAGE_HPP_
#define REMOTE_TEXTMESSAGE_HPP_

#include <string>
#include "boost/asio.hpp"
#include "boost/noncopyable.hpp"
#include "Message.hpp"


namespace remote {

namespace message {


class TextMessage : public Message, boost::noncopyable {
public:
  explicit TextMessage(const std::string& message);
  virtual ~TextMessage() { }
  virtual int size() const;

  virtual boost::asio::const_buffer serialize() const {
    return boost::asio::buffer(message_.c_str(), message_.size());
  }
private:
  std::string message_;
};


}  // namespace message

}  // namespace remote

#endif
