/// In my opinion, west const is clearer
void west()
{
  const int c_data = 4;
  const int new_c_data = 5;
  int data = 0;
  int new_data = 1;

  // mutable pointer to mutable data
  int* data_ptr = &data;
  // mutable pointer to const data
  const int* m_data_ptr = &c_data;
  // const pointer to mutable data
  int* const c_data_ptr = &data;
  // const pointer to const data
  const int* const c_c_data_ptr = &c_data;

  /// mutate pointer
  data_ptr = &new_data;
  /// mutate data
  *data_ptr = 10;

  /// mutate pointer
  m_data_ptr = &new_c_data;
  /// cannot mutate data
  // *m_data_ptr = 12;

  /// cannot mutate pointer
  // c_data_ptr = &new_c_data;
  /// mutate data
  *c_data_ptr = 5;

  /// cannot mutate pointer
  // c_c_data_ptr = &new_c_data;
  /// cannot mutate data
  // *c_c_data_ptr = 5;
}

void east()
{
  int const c_data = 4;
  int const new_c_data = 5;
  int data = 0;
  int new_data = 1;

  // mutable pointer to mutable data
  int* data_ptr = &data;
  // mutable pointer to const data
  int const* m_data_ptr = &c_data;
  // const pointer to mutable data
  int* const c_data_ptr = &data;
  // const pointer to const data
  int const* const c_c_data_ptr = &c_data;

  /// mutate pointer
  data_ptr = &new_data;
  /// mutate data
  *data_ptr = 10;

  /// mutate pointer
  m_data_ptr = &new_c_data;
  /// cannot mutate data
  // *m_data_ptr = 12;

  /// cannot mutate pointer
  // c_data_ptr = &new_c_data;
  /// mutate data
  *c_data_ptr = 5;

  /// cannot mutate pointer
  // c_c_data_ptr = &new_c_data;
  /// cannot mutate data
  // *c_c_data_ptr = 5;
}

int main()
{
  east();
  west();
}
