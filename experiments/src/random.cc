/// This file is completely random stuff. Honestly I'm just playing
/// around with my new Pok3r mechanical keyboard and just want to
/// type some code haha.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/// @brief Random function to check a string against an internal password
/// @param guess The users' guess of the password
/// @return Whether the guess matches the internal password
bool check_password(const std::string& guess) {
  // Very secure storage of the secret password
  return guess == "secret_password";
}

namespace util {

/// @brief utility function to print a vector
template <class T>
void print_vector(const std::vector<T>& vec) {
  std::for_each(std::begin(vec), std::end(vec),
                [] (const T& element) { std::cout << element << " "; });
  std::cout << '\n';
}

namespace v1
{

/// @brief Finds common elements between two vectors
/// @param v1 The first vector
/// @param v2 The second vector
/// @return A vector of common elements between the first and second vectors
template <class T>
std::vector<T> vector_intersection(const std::vector<T>& v1,
                                   const std::vector<T>& v2) {
  auto common = std::vector<T>();

  // No sorting needed ()
  std::copy_if(std::begin(v1), std::end(v1), std::back_inserter(common),
               [&v2] (const auto& el1) {
                 auto it = std::find_if(std::begin(v2), std::end(v2),
                     [&el1] (const auto& el2) { return el1 == el2; });
                 return it != std::end(v2);
               });

  return common;
}

}  // namespace v1

namespace v2
{

// Pro: uses std::set_intersection algorithm
// Con: requires either copying arguments to sort them or removing `const`
//      in main and passing by non-const ref (side effects)
template <class T>
std::vector<T> vector_intersection(std::vector<T> v1,
                                   std::vector<T> v2)
{
  auto common = std::vector<T>{};

  // Sort v1
  std::sort(std::begin(v1), std::end(v1));

  // Sort v2
  std::sort(std::begin(v2), std::end(v2));

  // std::set_intersection expects sorted inputs
  std::set_intersection(std::begin(v1), std::end(v1),
                        std::begin(v2), std::end(v2),
                        std::back_inserter(common));

  return common;
}

}  // namespace v2

}  // namespace util

int main() {
  // Part 1
  std::cout << "Hello, friend!" << '\n';

  // Part 2
  std::cout << "\nEnter a guess: ";
  std::string user_guess;
  std::getline(std::cin, user_guess);

  if (check_password(user_guess)) {
    std::cout << "Woah, you guessed the secret password!" << '\n';
  } else {
    std::cout << "Aw snap, you didn't guess the secret password" << '\n';
  }

  // Part 3
  const auto my_interests =
      std::vector<std::string>{"one", "two", "three", "four"};
  const auto your_interests =
      std::vector<std::string>{"six", "five", "four", "three"};
  const auto common_interests =
      util::v1::vector_intersection(my_interests, your_interests);

  std::cout << "\nMy interests:" << '\n';
  util::print_vector(my_interests);
  std::cout << "\nYour interests:" << '\n';
  util::print_vector(your_interests);
  std::cout << "\nCommon interests:" << '\n';
  util::print_vector(common_interests);
}
