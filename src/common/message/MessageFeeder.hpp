#ifndef REMOTE_MESSAGEFEEDER_HPP_
#define REMOTE_MESSAGEFEEDER_HPP_

#include <memory>
#include "Message.hpp"


namespace remote {


class MessageFeeder {
public:
  virtual ~MessageFeeder() { };
  virtual std::unique_ptr<Message> getMessage() = 0;
  virtual bool hasStoppedFeeding() const = 0;
}; 


} //remote

#endif