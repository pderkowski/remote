// Copyright 2013 <Piotr Derkowski>

#ifndef IMESSENGER_HPP_
#define IMESSENGER_HPP_

namespace remote {


class IMessenger {
public:
  virtual void deliver(const message::IMessage&) const = 0;
  virtual std::unique_ptr<message::IMessage> receive() const = 0;
};


}  // namespace remote

#endif
