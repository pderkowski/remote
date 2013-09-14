#ifndef REMOTE_TEXTMESSAGE_HPP_
#define REMOTE_TEXTMESSAGE_HPP_

#include "Message.hpp"

class boost::asio::const_buffer;


namespace remote {


class TextMessage : public Message {
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


} //remote

#endif