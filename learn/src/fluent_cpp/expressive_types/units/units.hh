#pragma once

#include <named_type.hh>
#include <traits.hh>

#include <cstdint>

namespace units
{

using Meter = util::convertible_named_type<double, struct DistanceTag,
      traits::Addable, traits::Subtractable, traits::Multiplicable,
      traits::Divisible, traits::Printable>;

using Kilometer = util::multiple_of<Meter, std::kilo>;

}  // namespace units

// NOLINTNEXTLINE(google-runtime-int)
units::Meter operator"" _meter(unsigned long long value);
units::Meter operator"" _meter(long double value);

// NOLINTNEXTLINE(google-runtime-int)
units::Kilometer operator"" _kilometer(unsigned long long value);
units::Kilometer operator"" _kilometer(long double value);
