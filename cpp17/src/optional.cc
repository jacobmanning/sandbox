#include <iostream>
#include <optional>
#include <string>
#include <vector>

class User {
public:
   User();
   User(const std::string& name, const int id) : name_{name}, unique_id_{id} {}
   User(const User& user) : name_{user.get_name()}, unique_id_{user.get_id()} {}

   std::string get_name() const { return name_; }

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

   UserDatabase(const UserDatabase& udb) : users_{udb.users_} {}
   UserDatabase(UserDatabase&& udb) : users_{std::move(udb.users_)} {}

   bool add_user(const std::string& name) {
      if (!get_user(name)) {
         users_.emplace_back(name, users_.size());
         return true;
      }
      return false;
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
