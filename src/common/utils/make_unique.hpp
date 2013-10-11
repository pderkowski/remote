// Copyright 2012 <Herb Sutter>
#ifndef COMMON_MAKE_UNIQUE_HPP_
#define COMMON_MAKE_UNIQUE_HPP_

#include <memory>
#include <utility>

namespace common {


template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


}  // namespace common

#endif  // COMMON_MAKE_UNIQUE_HPP_
