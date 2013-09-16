// Copyright 2013 <Piotr Derkowski>

#include <iostream>
#include <memory>
#include <string>
#include "utils/make_unique.hpp"
#include "TextMessageFeeder.hpp"
#include "TextMessage.hpp"

using utils::make_unique;

namespace remote {

namespace message {


TextMessageFeeder::TextMessageFeeder(std::istream& messageStream)  // NOLINT(runtime/references)
  : messageStream_(messageStream)
{ }

std::unique_ptr<IMessage> TextMessageFeeder::getMessage() {
  std::string message;
  std::getline(messageStream_, message);
  message += '\n';
  return make_unique<TextMessage>(message);
}

inline bool TextMessageFeeder::hasStoppedFeeding() const {
  return messageStream_.eof();
}


}  // namespace message

}  // namespace remote
