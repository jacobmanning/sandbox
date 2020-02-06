#pragma once

#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

namespace util
{
// Helper function to print a vector
template <class T>
void print_vector(const std::vector<T>& v)
{
  // Print all elements
  std::for_each(std::begin(v), std::end(v), [](const T& n) { std::cout << n << " "; });

  // Print separator
  std::cout << "\n\n";
}

namespace impl
{
// Variadic print_tuple implementation
template <class Tuple, std::size_t... Indices>
void print_tuple(const Tuple& t, std::ostream& os, std::index_sequence<Indices...>)
{
  ((os << std::get<Indices>(t) << " "), ...);
  os << '\n';
}

} // namespace impl

// Helper function to print the simple tuple example used here
template <template <class...> class TupleLike, class... Args>
void print_tuple(const TupleLike<Args...>& t, std::ostream& os = std::cout)
{
  impl::print_tuple(t, os, std::index_sequence_for<Args...>{});
}

} // namespace util
