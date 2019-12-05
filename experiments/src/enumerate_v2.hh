#pragma once

#include <cstdlib>
#include <iterator>
#include <type_traits>
#include <utility>

template <typename Rangeable>
class Enumerator
{
private:
  std::size_t index_;
  std::decay_t<decltype(std::begin(std::declval<Rangeable>()))> begin_;
  std::decay_t<decltype(std::end(std::declval<Rangeable>()))> end_;

public:
  Enumerator(Rangeable&& r) :
    index_{0}, begin_{std::begin(std::forward<Rangeable>(r))}, end_{std::end(std::forward<Rangeable>(r))} {}

  const Enumerator& begin() const
  {
    return *this;
  }

  const Enumerator& end() const
  {
    return *this;
  }

  bool operator!=(const Enumerator&) const
  {
    return begin_ != end_;
  }

  void operator++()
  {
    index_++;
    begin_++;
  }

  std::pair<std::size_t, decltype(*begin_)> operator*() const
  {
    return {index_, *begin_};
  }
};

template <typename Rangeable>
Enumerator<Rangeable> enumerate(Rangeable&& range)
{
  return {std::forward<Rangeable>(range)};
}
