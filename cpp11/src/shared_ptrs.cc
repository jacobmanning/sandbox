#include <my_class.h>

#include <iostream>
#include <memory>
#include <string>

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

int main() {
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
}
