#pragma once

#include <named_type.hh>
#include <traits.hh>

namespace units
{

using Meter = util::convertible_named_type<double, struct DistanceTag,
      traits::Addable, traits::Subtractable, traits::Multiplicable,
      traits::Divisible, traits::Printable>;

using Kilometer = util::multiple_of<Meter, std::kilo>;

}  // namespace units

units::Meter operator"" _meter(unsigned long long value);
units::Meter operator"" _meter(long double value);

units::Kilometer operator"" _kilometer(unsigned long long value);
units::Kilometer operator"" _kilometer(long double value);
