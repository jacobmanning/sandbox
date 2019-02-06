#include <sstream>

template <typename T>
DirectedGraph<T>::DirectedGraph(std::initializer_list<T> init) {
  assign(std::begin(init), std::end(init));
}

template <typename T>
template <typename Iter>
DirectedGraph<T>::DirectedGraph(Iter first, Iter last) {
  assign(first, last);
}

template <typename T>
template <typename Iter>
void DirectedGraph<T>::assign(Iter first, Iter last) {
  clear();

  for (auto iter = first; iter != last; ++iter) {
    insert(*iter);
  }
}

template <typename T>
void DirectedGraph<T>::assign(std::initializer_list<T> init) {
  assign(std::begin(init), std::end(init));
}

template <typename T>
std::pair<typename DirectedGraph<T>::iterator, bool>
DirectedGraph<T>::insert(T&& node_value) {
  if (auto iter = find(node_value); iter != std::end(nodes_)) {
    return std::make_pair(iterator(iter, this), false);
  }

  nodes_.emplace_back(std::move(node_value));
  return std::make_pair(iterator(--std::end(nodes_), this), true);
}

template <typename T>
std::pair<typename DirectedGraph<T>::iterator, bool>
DirectedGraph<T>::insert(const T& node_value) {
  auto copy_node_value = T(node_value);
  return insert(std::move(copy_node_value));
}

template <typename T>
typename DirectedGraph<T>::iterator DirectedGraph<T>::erase(const_iterator pos) {
  if (pos.node_iterator_ == std::end(nodes_)) {
    return iterator(std::end(nodes_), this);
  }

  remove_all_links_to(pos.node_iterator_);
  return iterator(nodes_.erase(pos.node_iterator_), this);
}

template <typename T>
typename DirectedGraph<T>::iterator DirectedGraph<T>::erase(
    const_iterator first, const_iterator last) {
  for (auto iter = first; iter != last; ++last) {
    if (iter.node_iterator_ != std::end(nodes_)) {
      remove_all_links_to(iter.node_iterator_);
    }
  }

  return iterator(nodes_.erase(first.node_iterator_, last.node_iterator_), this);
}

template <typename T>
bool DirectedGraph<T>::insert_edge(const T& from_node_value, const T& to_node_value) {
  const auto from = find(from_node_value);
  const auto to = find(to_node_value);

  if (from == std::end(nodes_) || to == std::end(nodes_)) {
    return false;
  }

  const auto to_index = std::distance(std::begin(nodes_), to);
  return from->get_adjacent_node_indices().insert(to_index).second;
}

template <typename T>
bool DirectedGraph<T>::erase_edge(const T& from_node_value, const T& to_node_value) {
  const auto from = find(from_node_value);
  const auto to = find(to_node_value);

  if (from == std::end(nodes_) || to == std::end(nodes_)) {
    return false;
  }

  const auto to_index = std::distance(std::begin(nodes_), to);
  from->get_adjacent_node_indices().erase(to_index);
  return true;
}

template <typename T>
std::size_t DirectedGraph<T>::size() const noexcept {
  return nodes_.size();
}

template <typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::max_size() const noexcept {
  return nodes_.max_size();
}

template <typename T>
void DirectedGraph<T>::clear() noexcept {
  nodes_.clear();
}

template <typename T>
bool DirectedGraph<T>::empty() const noexcept {
  return nodes_.empty();
}

template <typename T>
void DirectedGraph<T>::swap(DirectedGraph& other) noexcept {
  std::swap(nodes_, other.nodes_);
}

template <typename T>
std::set<T> DirectedGraph<T>::get_adjacent_node_values(const T& node_value) const {
  auto iter = find(node_value);

  if (iter == std::end(nodes_)) {
    return std::set<T>();
  }

  return get_adjacent_node_values(iter->get_adjacent_node_indices());
}

template <typename T>
bool DirectedGraph<T>::operator==(const DirectedGraph<T>& rhs) const {
  for (auto&& node : nodes_) {
    const auto result = rhs.find(node.get());

    if (result == std::end(rhs.nodes_)) {
      return false;
    }

    const auto adjacent_values_lhs = get_adjacent_node_values(
        node.get_adjacent_node_indices());
    const auto adjacent_values_rhs = rhs.get_adjacent_node_values(
        result->get_adjacent_node_indices());

    if (adjacent_values_lhs != adjacent_values_rhs) {
      return false;
    }
  }

  return true;
}

template <typename T>
bool DirectedGraph<T>::operator!=(const DirectedGraph& rhs) const {
  return !(*this == rhs);
}

template <typename T>
typename DirectedGraph<T>::reference DirectedGraph<T>::operator[](
    typename DirectedGraph<T>::size_type index) {
  return nodes_[index].get();
}

template <typename T>
typename DirectedGraph<T>::const_reference DirectedGraph<T>::operator[](
    typename DirectedGraph<T>::size_type index) const {
  return nodes_[index].get();
}

template <typename T>
typename DirectedGraph<T>::reference DirectedGraph<T>::at(typename DirectedGraph<T>::size_type index) {
  return nodes_.at(index).get();
}

template <typename T>
typename DirectedGraph<T>::const_reference DirectedGraph<T>::at(
    typename DirectedGraph<T>::size_type index) const {
  return nodes_.at(index).get();
}

template <typename T>
typename DirectedGraph<T>::iterator DirectedGraph<T>::begin() noexcept {
  return iterator(std::begin(nodes_), this);
}

template <typename T>
typename DirectedGraph<T>::iterator DirectedGraph<T>::end() noexcept {
  return iterator(std::end(nodes_), this);
}

template <typename T>
typename DirectedGraph<T>::const_iterator DirectedGraph<T>::begin() const noexcept {
  return const_cast<DirectedGraph*>(this)->begin();
}

template <typename T>
typename DirectedGraph<T>::const_iterator DirectedGraph<T>::end() const noexcept {
  return const_cast<DirectedGraph*>(this)->end();
}

template <typename T>
typename DirectedGraph<T>::const_iterator DirectedGraph<T>::cbegin() const noexcept {
  return const_cast<DirectedGraph*>(this)->begin();
}

template <typename T>
typename DirectedGraph<T>::const_iterator DirectedGraph<T>::cend() const noexcept {
  return const_cast<DirectedGraph*>(this)->end();
}

template <typename T>
typename DirectedGraph<T>::reverse_iterator DirectedGraph<T>::rbegin() noexcept {
  return reverse_iterator(end());
}

template <typename T>
typename DirectedGraph<T>::reverse_iterator DirectedGraph<T>::rend() noexcept {
  return reverse_iterator(begin());
}

template <typename T>
typename DirectedGraph<T>::const_reverse_iterator DirectedGraph<T>::rbegin() const noexcept {
  return const_cast<DirectedGraph*>(this)->rbegin();
}

template <typename T>
typename DirectedGraph<T>::const_reverse_iterator DirectedGraph<T>::rend() const noexcept {
  return const_cast<DirectedGraph*>(this)->rend();
}

template <typename T>
typename DirectedGraph<T>::const_reverse_iterator DirectedGraph<T>::rcbegin() const noexcept {
  return const_cast<DirectedGraph*>(this)->rbegin();
}

template <typename T>
typename DirectedGraph<T>::const_reverse_iterator DirectedGraph<T>::rcend() const noexcept {
  return const_cast<DirectedGraph*>(this)->rend();
}

template <typename T>
typename DirectedGraph<T>::const_iterator_adjacent_nodes
DirectedGraph<T>::begin(const T& node_value) const noexcept {
  auto iter = find(node_value);

  if (iter == std::end(nodes_)) {
    return adjacent_nodes_iterator<DirectedGraph>();
  }

  return adjacent_nodes_iterator<DirectedGraph>(
      std::begin(iter->get_adjacent_node_indices(), this));
}

template <typename T>
typename DirectedGraph<T>::const_iterator_adjacent_nodes
DirectedGraph<T>::end(const T& node_value) const noexcept {
  auto iter = find(node_value);

  if (iter == std::end(nodes_)) {
    return adjacent_nodes_iterator<DirectedGraph>();
  }

  return adjacent_nodes_iterator<DirectedGraph>(
      std::end(iter->get_adjacent_node_indices()), this);
}

template <typename T>
typename DirectedGraph<T>::const_iterator_adjacent_nodes
DirectedGraph<T>::cbegin(const T& node_value) const noexcept {
  return begin(node_value);
}

template <typename T>
typename DirectedGraph<T>::const_iterator_adjacent_nodes
DirectedGraph<T>::cend(const T& node_value) const noexcept {
  return end(node_value);
}

template <typename T>
typename DirectedGraph<T>::reverse_iterator_adjacent_nodes
DirectedGraph<T>::rbegin(const T& node_value) noexcept {
  return reverse_iterator(end());
}

template <typename T>
typename DirectedGraph<T>::reverse_iterator_adjacent_nodes
DirectedGraph<T>::rend(const T& node_value) noexcept {
  return reverse_iterator(begin());
}

template <typename T>
typename DirectedGraph<T>::const_reverse_iterator_adjacent_nodes
DirectedGraph<T>::rbegin(const T& node_value) const noexcept {
  return const_cast<DirectedGraph*>(this)->rbegin();
}

template <typename T>
typename DirectedGraph<T>::const_reverse_iterator_adjacent_nodes
DirectedGraph<T>::rend(const T& node_value) const noexcept {
  return const_cast<DirectedGraph*>(this)->rend();
}

template <typename T>
typename DirectedGraph<T>::const_reverse_iterator_adjacent_nodes
DirectedGraph<T>::crbegin(const T& node_value) const noexcept {
  return const_cast<DirectedGraph*>(this)->rbegin();
}

template <typename T>
typename DirectedGraph<T>::const_reverse_iterator_adjacent_nodes
DirectedGraph<T>::crend(const T& node_value) const noexcept {
  return const_cast<DirectedGraph*>(this)->rend();
}

template <typename T>
typename DirectedGraph<T>::nodes_container_type::iterator
DirectedGraph<T>::find(const T& node_value) {
  return std::find_if(
    std::begin(nodes_), std::end(nodes_),
    [&node_value](const auto& node) { return node.get() == node_value; }
  );
}

template <typename T>
typename DirectedGraph<T>::nodes_container_type::const_iterator
DirectedGraph<T>::find(const T& node_value) const {
  return const_cast<DirectedGraph<T>*>(this)->find(node_value);
}

template <typename T>
void DirectedGraph<T>::remove_all_links_to(
    typename nodes_container_type::const_iterator node) {
  const auto node_index = std::distance(std::cbegin(nodes_), node);

  for (auto&& node : nodes_) {
    auto& adjacent_indices = node.get_adjacent_node_indices();

    // Remove references to about-to-be-deleted node
    adjacent_indices.erase(node_index);

    // Modify all remaining adjacency lists
    for (auto iter = std::begin(adjacent_indices);
         iter != std::end(adjacent_indices);) {
      if (auto index = *iter; index > node_index) {
        auto hint = iter;
        ++hint;

        iter = adjacent_indices.erase(iter);

        adjacent_indices.insert(hint, index - 1);
      } else {
        ++iter;
      }
    }
  }
}

template <typename T>
std::set<T> DirectedGraph<T>::get_adjacent_node_values(
  const typename details::GraphNode<T>::adjacency_list_type& indices) const {
  auto values = std::set<T>();

  for (auto&& index : indices) {
    values.insert(nodes_[index].get());
  }

  return values;
}
