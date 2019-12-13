#include <iostream>
#include <named_type.hh>

namespace v1
{
template <typename Function>
struct Comparator : util::named_type<Function, Comparator<Function>>
{
  using util::named_type<Function, Comparator<Function>>::named_type;
};

template <typename Function>
Comparator<Function> comparator(const Function& func)
{
  return Comparator<Function>(func);
}

template <typename Function>
struct Aggregator : util::named_type<Function, Aggregator<Function>>
{
  using util::named_type<Function, Aggregator<Function>>::named_type;
};

template <typename Function>
Aggregator<Function> aggregator(const Function& func)
{
  return Aggregator<Function>(func);
}

template <typename Function1, typename Function2>
void set_aggregate(Comparator<Function1> c, Aggregator<Function2> a)
{
  std::cout << "Compare: " << c.get()() << '\n';
  std::cout << "Aggregate: " << a.get()() << '\n';
}

} // namespace v1

namespace v2
{
struct ComparatorParameter
{
};
template <typename Function>
using Comparator = util::named_type<Function, struct ComparatorParameter>;

struct AggregatorParameter
{
};
template <typename Function>
using Aggregator = util::named_type<Function, struct AggregatorParameter>;

template <template <typename T> class GenericTypeName, typename T>
GenericTypeName<T> make_named(const T& value)
{
  return GenericTypeName<T>(value);
}

template <typename Function1, typename Function2>
void set_aggregate(Comparator<Function1> c, Aggregator<Function2> a)
{
  std::cout << "Compare: " << c.get()() << '\n';
  std::cout << "Aggregate: " << a.get()() << '\n';
}

} // namespace v2

int main()
{
  v1::set_aggregate(v1::comparator([]() { return "compare"; }),
                    v1::aggregator([]() { return "aggreate"; }));

  v2::set_aggregate(v2::make_named<v2::Comparator>([]() { return "compare"; }),
                    v2::make_named<v2::Aggregator>([]() { return "aggreate"; }));
}
