#include <array>
#include <iostream>
#include <utility>

// Stateful fibonacci sequence using struct w/ overloaded operator()
struct FibStruct
{
  std::size_t operator()()
  {
    n0 = std::exchange(n1, n0 + n1);
    return n0;
  }

  std::size_t n0 = 0;
  std::size_t n1 = 1;
};

// Stateful fibonacci sequence using lambda
auto fib_lambda = [n0 = 0, n1 = 1]() mutable {
  n0 = std::exchange(n1, n0 + n1);
  return n0;
};

template <std::size_t N, typename Fib>
auto call(Fib&& fib)
{
  auto results = std::array<std::size_t, N>{};
  std::generate(std::begin(results), std::end(results), [&fib] { return fib(); });
  return results;
}

int main()
{
  constexpr auto n = 10U;

  const auto lambda_results = call<n>(fib_lambda);
  const auto struct_results = call<n>(FibStruct{});

  const auto results_match = std::equal(std::begin(lambda_results),
                                        std::end(lambda_results),
                                        std::begin(struct_results),
                                        std::end(struct_results));

  std::cout << std::boolalpha << results_match << std::endl;
}
