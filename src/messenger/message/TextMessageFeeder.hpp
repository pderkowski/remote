// Copyright 2013 <Piotr Derkowski>

#ifndef REMOTE_TEXTMESSAGEFEEDER_HPP_
#define REMOTE_TEXTMESSAGEFEEDER_HPP_

#include <istream>
#include <memory>
#include "boost/noncopyable.hpp"
#include "IMessageFeeder.hpp"


namespace remote {

namespace message {


class TextMessageFeeder : public IMessageFeeder, boost::noncopyable {
public:
  explicit TextMessageFeeder(std::istream& messageStream);  // NOLINT(runtime/references)
  virtual ~TextMessageFeeder() { }
  virtual std::unique_ptr<IMessage> getMessage();
  virtual bool hasStoppedFeeding() const;
private:
  std::istream& messageStream_;
};


}  // namespace message

}  // namespace remote

#endif
