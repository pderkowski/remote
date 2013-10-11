// Copyright 2013 <Piotr Derkowski>

#ifndef MESSENGER_TEXTMESSAGE_HPP_
#define MESSENGER_TEXTMESSAGE_HPP_

#include <string>
#include "boost/asio.hpp"

namespace messenger {


class TextMessage {
public:
  TextMessage()
    : message_()
  { }
  
  explicit TextMessage(const std::string& message)
    : message_(message)
  { }

private:
  friend std::istream& operator >> (std::istream& in, TextMessage& message);
  friend std::ostream& operator << (std::ostream& out, const TextMessage& message);

  std::string message_;
};

std::istream& operator >> (std::istream& in, TextMessage& message) {
  return in >> message.message_;
}

std::ostream& operator << (std::ostream& out, const TextMessage& message) {
  return out << message.message_;
}

}  // namespace messenger

#endif
