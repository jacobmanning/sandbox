#include "logging.h"

#include <iostream>
#include <memory>
#include <string>

struct MyStruct {
    int counter;
    std::string my_str;
};

bool use_my_struct(const std::shared_ptr<MyStruct>& obj) {
    if (obj->counter > 0) {
        LOG_INFO("Counter = " << obj->counter << ", my_str = " << obj->my_str);
    } else {
        obj->counter++;
        return false;
    }

    obj->counter++;
    obj->my_str += std::string("z");
    return true;
}

int main() {
    auto s1 = MyStruct{-1, "hello"};
    auto s2 = MyStruct{1, "hi"};

    auto s1_ptr = std::make_shared<MyStruct>(s1);
    auto s2_ptr = std::make_shared<MyStruct>(s2);

    for (int _i = 0; _i < 3; _i++) {
        if (use_my_struct(s1_ptr)) {
            LOG_INFO("s1 successful");
        } else {
            LOG_ERROR("s1 NOT successful");
        }

        if (use_my_struct(s2_ptr)) {
            LOG_INFO("s2 successful");
        } else {
            LOG_ERROR("s2 NOT successful");
        }
    }

    LOG_INFO("s1.counter = " << s1.counter << ", s1.my_str = " << s1.my_str);
    LOG_INFO("s2.counter = " << s2.counter << ", s2.my_str = " << s2.my_str);
}
