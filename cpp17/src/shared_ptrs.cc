#include <my_class.h>
#include <logging.h>

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class DummyClass {
public:
    DummyClass() : DummyClass{0} {}
    DummyClass(int id) : shared_id_{id} {
        my_class_ptr_ = std::make_shared<MyClass>("dummy", id);
    }

    DummyClass(int id, std::shared_ptr<MyClass> class_ptr)
        : shared_id_{id}, my_class_ptr_{class_ptr} {}

    void increment_shared_id() {
        shared_id_++;
    }

    int get_shared_id() const {
        return shared_id_;
    }

    std::shared_ptr<MyClass> get_my_class_ptr() const {
        return my_class_ptr_;
    }

private:
    int shared_id_{0};
    std::vector<int> values_{};
    std::shared_ptr<MyClass> my_class_ptr_{};
};

int main() {
    auto dummy_ptr = std::make_shared<DummyClass>();
    auto dummy_ptr_2 = std::make_shared<DummyClass>(dummy_ptr->get_shared_id(),
                            dummy_ptr->get_my_class_ptr());

    LOG_INFO("DummyClass shared id: " << dummy_ptr->get_shared_id());
    dummy_ptr->increment_shared_id();
    LOG_INFO("After incrementing original pointer: " << dummy_ptr->get_shared_id());
    dummy_ptr_2->increment_shared_id();
    LOG_INFO("After incrementing copy pointer: " << dummy_ptr->get_shared_id());

}

int multiply_myclass_id(const MyClass& multiplicand, const int multiplier) {
    return multiplicand.get_id() * multiplier;
}

int multiply_myclass_id(const std::shared_ptr<MyClass>& multiplicand,
                        const int multiplier) {
    return multiplicand->get_id() * multiplier;
}

std::shared_ptr<MyClass> copy_shared_ptr(std::shared_ptr<MyClass> original) {
    return std::shared_ptr<MyClass>(original);
}

int old_main() {
    auto test_class_ptr = std::make_shared<MyClass>("test_ptr", 1);
    auto test_class_ref = MyClass("test_ref", 2);

    std::cout << "Test_Ptr MyClass:\n" << *test_class_ptr << "\n";
    std::cout << "Test_Ref MyClass:\n" << test_class_ref << "\n";

    int result1 = multiply_myclass_id(test_class_ref, 4);
    std::cout << "Result1 = " << test_class_ref.get_id() << " * 4 = " << result1
              << "\n";

    int result2 = multiply_myclass_id(test_class_ptr, result1);
    std::cout << "Result2 = " << test_class_ptr->get_id() << " * " << result1
              << " = " << result2 << "\n\n";

    auto test_class_ptr2 = copy_shared_ptr(test_class_ptr);
    std::cout << "Shared pointer use_count() = " << test_class_ptr2.use_count()
              << "\n";
    return 0;
}
