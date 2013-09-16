// Copyright 2013 <Piotr Derkowski>

#ifndef REMOTE_IMESSAGEFEEDER_HPP_
#define REMOTE_IMESSAGEFEEDER_HPP_

#include <memory>
#include "boost/noncopyable.hpp"
#include "IMessage.hpp"

namespace remote {

namespace message {


class IMessageFeeder {
public:
  virtual ~IMessageFeeder() { }
  virtual std::unique_ptr<IMessage> getMessage() = 0;
  virtual bool hasStoppedFeeding() const = 0;
};


}  // namespace message

}  // namespace remote

#endif
