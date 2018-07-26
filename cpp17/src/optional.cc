#include <algorithm>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

class User {
public:
   User();
   User(const std::string& name, int id) : name_{name}, unique_id_{id} {}

   std::string get_name() const { return name_; }
   int get_id() const { return unique_id_; }

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

   bool add_user(const std::string& name) {
      if (!get_user(name)) {
         users_.emplace_back(name, users_.size());
         return true;
      }
      return false;
   }

   std::optional<User> get_user(const std::string& name) {
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
   auto db = UserDatabase({"foo", "bar", "woo"});

   if (auto maybe_user = db.get_user("woo"); maybe_user) {
      std::cout << "Found user 'woo' with id: " << maybe_user.value().get_id()
                << std::endl;
   } else {
      std::cerr << "Could not find user 'woo'" << std::endl;
   }

   if (auto maybe_user = db.get_user("test"); maybe_user) {
      std::cout << "Found user 'test' with id: " << maybe_user.value().get_id()
                << std::endl;
   } else {
      std::cerr << "Could not find user 'test'" << std::endl;
   }
}
