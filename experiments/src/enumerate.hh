#pragma once

#include <algorithm>
#include <iterator>
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
                          std::input_iterator_tag>>;

/// Ensure that the BinaryOperandFunction can be called with parameter types and
/// that the return type is convertible to the expected return type
template <typename BinaryOperandFunction,
          typename Parameter1Type,
          typename Parameter2Type,
          typename ReturnType>
using RequireInvocableBinaryOperandFunction = typename std::enable_if_t<
    std::is_invocable_v<BinaryOperandFunction, Parameter1Type, Parameter2Type> &&
    std::is_convertible_v<
        std::invoke_result_t<BinaryOperandFunction, Parameter1Type, Parameter2Type>,
        ReturnType>>;

template <
    typename InputIt,
    typename BinaryOperandFunction,
    typename LoopElementType = typename std::iterator_traits<InputIt>::value_type,
    typename = RequireInputIterator<InputIt>,
    typename =
        RequireInvocableBinaryOperandFunction<BinaryOperandFunction, int, LoopElementType, void>>
auto enumerate(InputIt begin, InputIt end, BinaryOperandFunction loop_body)
{
  auto runnable_loop_body = [i = 0, loop_body = std::move(loop_body)](auto&& element) mutable {
    loop_body(i++, std::forward<decltype(element)>(element));
  };

  std::for_each(begin, end, runnable_loop_body);
}

template <
    typename Range,
    typename BinaryOperandFunction,
    typename It = decltype(std::begin(std::declval<Range>())),
    typename LoopElementType = typename std::iterator_traits<It>::value_type,
    typename = RequireInputIterator<It>,
    typename =
        RequireInvocableBinaryOperandFunction<BinaryOperandFunction, int, LoopElementType, void>>
auto enumerate(Range range, BinaryOperandFunction loop_body)
{
  enumerate(std::begin(range), std::end(range), loop_body);
}

} // namespace util
