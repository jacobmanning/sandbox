#include "my_class.h"
#include "util.h"

#include <algorithm>
#include <iostream>

// NOLINTNEXTLINE(google-runtime-references)
void use_my_class(MyClass& obj) {
    auto& ids_mut = obj.get_log_ids_mutable();

    util::print_vector(ids_mut);

    std::for_each(std::begin(ids_mut), std::end(ids_mut),
                   [] (auto& el) { el *= 2; });

    util::print_vector(ids_mut);
}

int main() {
    auto obj = MyClass{"my_name", 1337};

    obj.append_log_id(3);
    obj.append_log_id(2);
    obj.append_log_id(1);

    use_my_class(obj);

    util::print_vector(obj.get_log_ids());

    obj.get_log_id_at_mutable(0) *= 3;
    std::cout << "my_obj.get_log_id_at(0) = " << obj.get_log_id_at(0) << '\n';

    // Copy constructor
    auto new_obj = obj;

    obj.append_log_id(4);
    std::cout << "y = " << obj.get_log_id_at(3) << '\n';

    new_obj.append_log_id(6);
    std::cout << "z = " << new_obj.get_log_id_at(3) << '\n';
}
