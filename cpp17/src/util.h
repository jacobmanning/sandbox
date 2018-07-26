#pragma once
#ifndef _UTIL_H
#define _UTIL_H

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

namespace util {

/**
 * Helper function to print a vector
 */
template <class T>
void print_vector(const std::vector<T>& v) {
    // Print all elements
    std::for_each(std::begin(v), std::end(v),
                  [](T n) { std::cout << n << " "; });

    // Print separator
    std::cout << "\n\n";
}

/**
 * Helper function to print the simple tuple example used here
 */
template <class T, class U, class V>
void print_tuple(const std::tuple<T, U, V>& t) {
    std::cout << "First: " << std::get<0>(t) << ". "
              << "Second: " << std::get<1>(t) << ". "
              << "Third: " << std::get<2>(t) << std::endl;
}

}  // namespace util

#endif  // _UTIL_H
