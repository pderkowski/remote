// Copyright 2012 <Herb Sutter>
#ifndef UTILS_MAKE_UNIQUE_HPP_
#define UTILS_MAKE_UNIQUE_HPP_

#include <memory>
#include <utility>


namespace utils {


template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


}  // namespace utils


#endif
