#include "logging.h"
#include "my_class.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class MyClassWrapper
{
public:
  MyClassWrapper() : MyClassWrapper{0}
  {
  }

  explicit MyClassWrapper(int id) : ptr_{std::make_shared<MyClass>("wrapper", id)}
  {
  }

  explicit MyClassWrapper(std::shared_ptr<MyClass> class_ptr) : ptr_{std::move(class_ptr)}
  {
  }

  // ~MyClassWrapper() = default;
  // MyClassWrapper(const MyClassWrapper& other) = default;
  // MyClassWrapper(MyClassWrapper&& other) = default;
  // MyClassWrapper& operator=(const MyClassWrapper&) = default;
  // MyClassWrapper& operator=(MyClassWrapper&&) = default;

  void increment_shared_id()
  {
    ptr_->increment_id();
  }

  int get_shared_id() const
  {
    return ptr_->get_id();
  }

  std::shared_ptr<MyClass> get_ptr() const
  {
    return ptr_;
  }

private:
  std::shared_ptr<MyClass> ptr_{};
};

int main()
{
  auto x = MyClassWrapper{5};
  auto y = MyClassWrapper{x};

  LOG_INFO("MyClassWrapper shared id: " << x.get_shared_id());
  x.increment_shared_id();
  LOG_INFO("After incrementing original pointer: " << x.get_shared_id());
  y.increment_shared_id();
  LOG_INFO("After incrementing copy pointer: " << y.get_shared_id());
}
