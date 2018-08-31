#include <my_class.h>
#include <iostream>

// void use_my_class(const MyClass& my_obj) {
void use_my_class(MyClass& my_obj) {
    // Get const reference to log_ids_ vector
    // const auto& obj_vec = my_obj.get_log_ids();
    auto& obj_vec_m = my_obj.get_log_ids_mutable();

    for (const auto& el : obj_vec_m) {
        std::cout << el << " ";
    }

    std::cout << "\n";

    for (auto& el : obj_vec_m) {
        el *= 2;
        std::cout << el << " ";
    }

    std::cout << "\n";
}

int main() {
    auto my_obj_m = MyClass{"my_name", 1337};
    // const auto my_obj = MyClass{"my_name", 1337};

    my_obj_m.append_log_id(3);
    my_obj_m.append_log_id(2);
    my_obj_m.append_log_id(1);

    use_my_class(my_obj_m);

    for (const auto& el : my_obj_m.get_log_ids()) {
        std::cout << el << " ";
    }

    std::cout << "\n";

    auto& x = my_obj_m.get_log_id_at_mutable(0);
    x *= 3;
    std::cout << "x = " << x << std::endl;
    std::cout << "my_obj.get_lod_id_at(0) = " << my_obj_m.get_log_id_at(0)
              << std::endl;

    auto my_new_obj = std::move(my_obj_m);

    my_obj_m.append_log_id(4);
    auto& y = my_obj_m.get_log_id_at_mutable(3);
    std::cout << "y = " << y << std::endl;

    my_new_obj.append_log_id(6);
    auto& z = my_new_obj.get_log_id_at_mutable(3);
    std::cout << "z = " << z << std::endl;
}
