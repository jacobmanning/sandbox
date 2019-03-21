#pragma once

#include <named_type.hh>

namespace units
{

struct MeterParameter {};
using Meter = util::v1::named_type<double, struct MeterParameter>;

}  // namespace units

units::Meter operator"" _meter(unsigned long long value);
units::Meter operator"" _meter(long double value);
