#ifndef REMOTE_TEXTMESSAGEFEEDER_HPP_
#define REMOTE_TEXTMESSAGEFEEDER_HPP_

#include <istream>
#include <memory>
#include "MessageFeeder.hpp"


namespace remote {


class TextMessageFeeder : public MessageFeeder {
public:
  TextMessageFeeder(std::istream& messageStream);
  virtual ~TextMessageFeeder() { }
  virtual std::unique_ptr<Message> getMessage();
  virtual bool hasStoppedFeeding() const;
private:
  std::istream& messageStream_;
};


} //remote

#endif