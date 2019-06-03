#include <iostream>
#include <optional>
#include <string>
#include <vector>

class User {
public:
   User() = default;
   User(std::string name, const int id) :
      name_{std::move(name)}, unique_id_{id} {}

   // ~User() = default;
   // User(const User&) = default;
   // User(User&&) = default;
   // User& operator=(const User&) = default;
   // User& operator=(User&&) = default;

   const std::string& get_name() const { return name_; }

   int get_id() const { return unique_id_; }

   friend std::ostream& operator<<(std::ostream& os, const User& user) {
      os << "Name: " << user.get_name() << ", ID: " << user.get_id()
         << std::endl;
      return os;
   }

private:
   std::string name_{"default"};
   int unique_id_{-1};
};

class UserDatabase {
public:
   UserDatabase(std::initializer_list<std::string> names) {
      for (const auto& name : names) {
         if (!add_user(name)) {
            std::cerr << "Cannot add user: " << name << std::endl;
         }
      }
   }

   // ~UserDatabase() = default;
   // UserDatabase(const UserDatabase& udb) = default;
   // UserDatabase(UserDatabase&& udb) = default;
   // UserDatabase& operator=(const UserDatabase&) = default;
   // UserDatabase& operator=(UserDatabase&&) = default;

   bool add_user(const std::string& name) {
      if (get_user(name)) {
         return false;
      }

      users_.emplace_back(name, users_.size());
      return true;
   }

   std::optional<User> get_user(const std::string& name) const {
      for (const auto& user : users_) {
         if (user.get_name() == name) {
            return user;
         }
      }

      return {};
   }

private:
   std::vector<User> users_;
};

int main() {
   const auto db = UserDatabase({"foo", "bar", "woo"});
   const auto names = {"woo", "test"};

   for (const auto& name : names) {
      if (auto maybe_user = db.get_user(name); maybe_user) {
         // const auto& user = *maybe_user;
         // std::cout << "Found: " << user;
         std::cout << "Found: " << *maybe_user;
      } else {
         std::cout << "Could not find: " << name << std::endl;
      }
   }
}
