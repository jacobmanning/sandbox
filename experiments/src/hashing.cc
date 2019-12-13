#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>

/// @brief Reads a string from the user via the console and hashes it
/// @return The hash of the string the user inputs
unsigned long get_string_and_hash()
{
  std::cout << "Enter a string to hash: ";
  auto my_string = std::string{};
  std::getline(std::cin, my_string);
  std::cout << "You entered: " << my_string << '\n';

  const auto my_hasher = std::hash<std::string>();
  return my_hasher(my_string);
}

/// @brief Writes a hash to a file
/// @param filename The filename to write the hash to
/// @param my_hash The hash to write to the file
/// @return The success of opening the filename for writing
bool write_hash_to_file(const std::string& filename, const unsigned long my_hash)
{
  auto out_file = std::ofstream{filename, std::ios::out};
  if (!out_file.is_open())
  {
    std::cerr << "Could not open output file" << '\n';
    return false;
  }

  out_file << my_hash;
  out_file.close();
  return true;
}

/// @brief Reads a hash from the specified filename and returns an
///        optional to the hash
/// @param filename The filename to read the hash from
/// @return An optional to the hash. If the input file cannot be opened,
///         an empty optional will be returned
std::optional<unsigned long> read_hash_from_file(const std::string& filename)
{
  auto in_file = std::ifstream{filename, std::ios::in};
  if (!in_file.is_open())
  {
    std::cerr << "Could not open input file" << '\n';
    return {};
  }

  auto my_hash = std::string{};
  std::getline(in_file, my_hash);
  return strtoul(my_hash.c_str(), nullptr, 0);
}

/// @brief Main function
int main()
{
  // The filename to write/read the hash to/from
  const auto hash_filename = std::string("hash_file.txt");

  // Get input from the user and hash it
  const auto my_hash = get_string_and_hash();
  std::cout << "Hashed: " << my_hash << '\n';

  // Write the user's hash to the file
  if (!write_hash_to_file(hash_filename, my_hash))
  {
    std::cerr << "Could not write hash to file: " << hash_filename << '\n';
    return 1;
  }

  // Read the hash from the file
  const auto hash_from_file = read_hash_from_file(hash_filename);
  if (!hash_from_file)
  {
    std::cerr << "Could not read hash from file: " << hash_filename << '\n';
    return 1;
  }

  if (my_hash != *hash_from_file)
  {
    std::cerr << "Hashes do NOT match!" << '\n';
    return 1;
  }

  std::cout << "Hashes match!" << '\n';
  return 0;
}
