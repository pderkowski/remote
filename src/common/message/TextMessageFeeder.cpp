#include <iostream>
#include <memory>
#include <utils/make_unique.hpp>
#include "TextMessageFeeder.hpp"
#include "TextMessage.hpp"

using utils::make_unique;


remote::TextMessageFeeder::TextMessageFeeder(std::istream& messageStream)
  : messageStream_(messageStream)
{ }

std::unique_ptr<remote::Message> remote::TextMessageFeeder::getMessage() {
  std::string message;
  std::getline(messageStream_, message);
  message += '\n';
  return make_unique<remote::TextMessage>(message);
}

inline bool remote::TextMessageFeeder::hasStoppedFeeding() const {
  return messageStream_.eof();
}
