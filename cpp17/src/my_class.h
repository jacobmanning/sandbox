#pragma once

#include "int_wrapper.h"

#include <iostream>
#include <string>
#include <vector>

class MyClass {
public:
    MyClass() : MyClass("default") {};

    explicit MyClass(std::string tag) : MyClass(tag, 0) {};

    MyClass(std::string tag, int id) : log_ids_{}, tag_{std::move(tag)}, id_{id} {
        std::cout << "Constructing MyClass\n";
    }

    ~MyClass() { std::cout << "Deconstructing MyClass\n"; }

    MyClass(const MyClass& other) = default;
    MyClass(MyClass&& other) noexcept = default;
    MyClass& operator=(const MyClass&) = default;
    MyClass& operator=(MyClass&&) = default;

    const std::vector<int>& get_log_ids() const { return log_ids_; }

    std::vector<int>& get_log_ids_mutable() { return log_ids_; }

    int get_log_id_at(int idx) const { return log_ids_.at(idx); }

    int& get_log_id_at_mutable(int idx) { return log_ids_.at(idx); }

    const std::string& get_tag() const { return tag_; }

    int get_id() const { return id_; }

    void set_tag(std::string tag) { tag_ = std::move(tag); }

    void set_id(int id) { id_ = id; }

    void increment_id() { ++id_; }

    void append_log_id(int id) { log_ids_.push_back(id); }

    void print(std::ostream& os = std::cout) const {
        os << "Tag: " << get_tag() << "\nID: " << get_id() << "\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const MyClass& mc) {
        mc.print(os);
        return os;
    }

private:
    std::vector<int> log_ids_;
    std::string tag_;
    int id_;
};
