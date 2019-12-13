#include <iostream>
#include <memory>

class Widget
{
public:
  Widget() = default;
  ~Widget() = default;
  Widget(const Widget&) = default;
  Widget(Widget&&) = default;
  Widget& operator=(const Widget&) = default;
  Widget& operator=(Widget&&) = default;

  [[nodiscard]] int get_id() const
  {
    return id_;
  }
  [[nodiscard]] int get_num_increments() const
  {
    return num_increments_;
  }

  void increment_id()
  {
    ++num_increments_;
    ++id_;
  }

private:
  int id_{0};
  int num_increments_{0};
};

void print_widget(const Widget& w)
{
  std::cout << "Widget::get_id() = " << w.get_id() << '\n';
  std::cout << "Widget::get_num_increments() = " << w.get_num_increments() << '\n';
}

// NOLINTNEXTLINE(google-runtime-references)
void increment_widget(Widget& w)
{
  // NOLINTNEXTLINE
  std::cout << __PRETTY_FUNCTION__ << '\n';
  w.increment_id();
}

void increment_widget(Widget* w)
{
  // NOLINTNEXTLINE
  std::cout << __PRETTY_FUNCTION__ << '\n';
  if (w != nullptr)
  {
    w->increment_id();
  }
}

int main()
{
  auto widget_ptr = std::make_unique<Widget>();
  print_widget(*widget_ptr);

  increment_widget(*widget_ptr);
  increment_widget(widget_ptr.get());

  print_widget(*widget_ptr);
}
