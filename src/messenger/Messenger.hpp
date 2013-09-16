// Copyright 2013 <Piotr Derkowski>

#ifndef MESSENGER_HPP_
#define MESSENGER_HPP_

#include "IMessenger.hpp"


namespace remote {


class Messenger : public IMessenger {
public:
  explicit Messenger(std::shared_ptr<boost::asio::ip::tcp::socket>);

  virtual void deliver(const message::Message&) const;
  virtual std::unique_ptr<message::Message> receive() const;

private:
  std::shared_ptr<boost::asio::ip::tcp::socket> socket_;
};


}  // namespace remote

#endif
