#pragma once

#include <iostream>
#include <set>

namespace details {

template <typename T>
class GraphNode {
public:
  using adjacency_list_type = std::set<std::size_t>;

  explicit GraphNode(const T& t);
  explicit GraphNode(T&& t);

  T& get() noexcept;
  const T& get() const noexcept;

  bool operator==(const GraphNode& rhs) const;
  bool operator!=(const GraphNode& rhs) const;

  void swap(GraphNode& other) noexcept;

  adjacency_list_type& get_adjacent_node_indices();
  const adjacency_list_type& get_adjacent_node_indices() const;

private:
  T data_;
  adjacency_list_type adjacent_node_indices_;
};

} // namespace details

#include "GraphNode.inl"
