template <typename T, typename Parameter, template <typename> class... Skills>
std::ostream& operator<<(std::ostream& os, const util::v3::named_type<T, Parameter, Skills...>& obj)
{
  obj.print(os);
  return os;
}

template <typename T, typename Tag, typename Converter, template <typename> class... Skills>
std::ostream& operator<<(std::ostream& os,
                         const util::v4::named_type_impl<T, Tag, Converter, Skills...>& obj)
{
  obj.print(os);
  return os;
}

namespace std
{
template <typename T, typename Parameter, template <typename> class... Skills>
struct hash<util::v3::named_type<T, Parameter, Skills...>>
{
  using named_type_t = util::v3::named_type<T, Parameter, Skills...>;
  using check_if_hashable = typename std::enable_if_t<named_type_t::is_hashable, void>;

  size_t operator()(const named_type_t& x) const
  {
    return std::hash<T>()(x.get());
  }
};

template <typename T, typename Parameter, typename Converter, template <typename> class... Skills>
struct hash<util::v4::named_type_impl<T, Parameter, Converter, Skills...>>
{
  using named_type_t = util::v4::named_type_impl<T, Parameter, Converter, Skills...>;
  using check_if_hashable = typename std::enable_if_t<named_type_t::is_hashable, void>;

  size_t operator()(const named_type_t& x) const
  {
    return std::hash<T>()(x.get());
  }
};

} // namespace std
