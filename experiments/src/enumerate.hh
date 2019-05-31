#pragma once

#include <algorithm>
#include <type_traits>

namespace util
{

/// Ensure that template parameter is an iterator
///
/// Source:
/// https://stackoverflow.com/questions/4335962/
///   how-to-check-if-a-template-parameter-is-an-iterator-type-or-not
template <typename InputIterator>
using RequireInputIterator = typename std::enable_if_t<
  std::is_convertible_v<typename std::iterator_traits<InputIterator>::iterator_category,
                        std::input_iterator_tag>
>;

/// Ensure that the BinaryOperandFunction can be called with parameter types and that
/// the return type is convertible to the expected return type
template <typename BinaryOperandFunction,
          typename Parameter1Type,
          typename Parameter2Type,
          typename ReturnType>
using RequireInvocableBinaryOperandFunction = typename std::enable_if_t<
  std::is_invocable_v<BinaryOperandFunction, Parameter1Type, Parameter2Type> &&
  std::is_convertible_v<std::invoke_result_t<BinaryOperandFunction, Parameter1Type, Parameter2Type>,
                        ReturnType>
>;

template <typename InputIt, typename BinaryOperandFunction,
          typename LoopElementType = typename std::iterator_traits<InputIt>::value_type,
          typename = RequireInputIterator<InputIt>,
          typename = RequireInvocableBinaryOperandFunction<BinaryOperandFunction, int, LoopElementType, void>>
auto enumerate(InputIt begin, InputIt end, BinaryOperandFunction loop_body)
{
  auto i = int{0};

  auto runnable_loop_body = [&i, &loop_body] (auto&& element) {
    loop_body(i++, std::forward<decltype(element)>(element));
  };

  std::for_each(begin, end, runnable_loop_body);
}

}  // namespace util
