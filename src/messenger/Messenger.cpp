// Copyright 2013 <Piotr Derkowski>

#include "Messenger.hpp"


namespace remote {


Messenger::Messenger(std::shared_ptr<boost::asio::ip::tcp::socket> socket)
    : socket_(socket)
{ }

void Messenger::deliver(const message::Message&) const { }

std::unique_ptr<message::Message> Messenger::receive() const {
  return make_unique<message::TextMessage>();
}


}  // namespace remote
