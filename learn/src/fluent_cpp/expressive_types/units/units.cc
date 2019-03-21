#include <units.hh>

units::Meter operator"" _meter(unsigned long long value)
{
  return units::Meter{value};
}

units::Meter operator"" _meter(long double value)
{
  return units::Meter{value};
}
