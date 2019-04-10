#include <units.hh>

// NOLINTNEXTLINE(google-runtime-int)
units::Meter operator"" _meter(unsigned long long value)
{
  return units::Meter{value};
}

units::Meter operator"" _meter(long double value)
{
  return units::Meter{value};
}

// NOLINTNEXTLINE(google-runtime-int)
units::Kilometer operator"" _kilometer(unsigned long long value)
{
  return units::Kilometer(value);
}

units::Kilometer operator"" _kilometer(long double value)
{
  return units::Kilometer(value);
}
