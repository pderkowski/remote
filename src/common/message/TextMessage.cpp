#include <boost/asio.hpp>
#include "TextMessage.hpp"


remote::TextMessage::TextMessage(const std::string& message)
  : message_(message) 
{ }

inline int remote::TextMessage::size() const {
  return message_.size();
}