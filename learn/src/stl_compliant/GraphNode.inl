namespace details {

template <typename T>
GraphNode<T>::GraphNode(const T& t) : data_{t} {};

template <typename T>
GraphNode<T>::GraphNode(T&& t) : data_{std::move(t)} {};

template <typename T>
typename GraphNode<T>::adjacency_list_type&
GraphNode<T>::get_adjacent_node_indices() {
  return adjacent_node_indices_;
}

template <typename T>
const typename GraphNode<T>::adjacency_list_type&
GraphNode<T>::get_adjacent_node_indices() const {
  return adjacent_node_indices_;
}

template <typename T>
T& GraphNode<T>::get() noexcept {
  return data_;
}

template <typename T>
const T& GraphNode<T>::get() const noexcept {
  return data_;
}

template <typename T>
bool GraphNode<T>::operator==(const GraphNode& rhs) const {
  return data_ == rhs.data_ &&
         adjacent_node_indices_ == rhs.adjacent_node_indices_;
}

template <typename T>
bool GraphNode<T>::operator!=(const GraphNode& rhs) const {
  return !(*this == rhs);
}

template <typename T>
void GraphNode<T>::swap(GraphNode& other) noexcept {
  std::swap(data_, other.data_);
  std::swap(adjacent_node_indices_, other.adjacent_node_indices_);
}

} // namespace details
