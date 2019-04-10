#pragma once
#ifndef MY_CLASS_H_
#define MY_CLASS_H_

#include "int_wrapper.h"
#include <iostream>
#include <string>
#include <vector>

class MyClass {
private:
    std::vector<int> log_ids_;
    std::string tag_;
    int id_;

public:
    MyClass() : MyClass("default") {};
    explicit MyClass(std::string tag) : MyClass(std::forward<std::string>(tag), 0) {};
    MyClass(std::string tag, int id) : tag_{std::move(tag)}, id_{id} {
        std::cout << "Constructing MyClass\n";
    }

    ~MyClass() { std::cout << "Deconstructing MyClass\n"; }

    /// @brief Copy constructor
    MyClass(const MyClass& other) {
        tag_ = other.tag_;
        id_ = other.id_;
        log_ids_ = other.log_ids_;
    }

    /// @brief Move constructor
    MyClass(const MyClass&& other) noexcept {
        tag_ = other.tag_;
        id_ = other.id_;
        log_ids_ = other.log_ids_;
    }

    MyClass& operator=(const MyClass&) = default;
    MyClass& operator=(MyClass&&) = default;

    const std::vector<int>& get_log_ids() const { return log_ids_; }

    std::vector<int>& get_log_ids_mutable() { return log_ids_; }

    int get_log_id_at(int idx) const { return log_ids_.at(idx); }

    int& get_log_id_at_mutable(int idx) { return log_ids_.at(idx); }

    std::string get_tag() const { return tag_; }

    int get_id() const { return id_; }

    void set_tag(const std::string& tag) { tag_ = tag; }
    void set_tag(std::string&& tag) { tag_ = std::move(tag); }

    void set_id(int id) { id_ = id; }

    void append_log_id(int id) { log_ids_.push_back(id); }

    void print(std::ostream& os = std::cout) const {
        os << "Tag: " << get_tag() << "\nID: " << get_id() << "\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const MyClass& mc) {
        mc.print(os);
        return os;
    }
};

#endif  // MY_CLASS_H_
