// Copyright 2013 <Piotr Derkowski>

#ifndef REMOTE_MESSAGEFEEDER_HPP_
#define REMOTE_MESSAGEFEEDER_HPP_

#include <memory>
#include "boost/noncopyable.hpp"
#include "Message.hpp"

namespace remote {


class MessageFeeder {
public:
  virtual ~MessageFeeder() { }
  virtual std::unique_ptr<Message> getMessage() = 0;
  virtual bool hasStoppedFeeding() const = 0;
};


}  // namespace remote

#endif
