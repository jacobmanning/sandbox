#pragma once

#include <algorithm>
#include <iostream>
// #include <iterator>
#include <set>
#include <vector>

#include "GraphNode.hh"

// Forward-declare helper classes
template<class DG> class const_directed_graph_iterator;
template<class DG> class adjacent_nodes_iterator;
template<class DG> class const_adjacent_nodes_iterator;

template <typename T>
class DirectedGraph {
public:
  friend class const_directed_graph_iterator<DirectedGraph>;

  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;

  // Unsafe to change values (std::set) so both iterators const
  using iterator = const_directed_graph_iterator<DirectedGraph>;
  using const_iterator = const_directed_graph_iterator<DirectedGraph>;

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  using iterator_adjacent_nodes = adjacent_nodes_iterator<DirectedGraph>;
  using const_iterator_adjacent_nodes = const_adjacent_nodes_iterator<DirectedGraph>;

  using reverse_iterator_adjacent_nodes = std::reverse_iterator<iterator_adjacent_nodes>;
  using const_reverse_iterator_adjacent_nodes = std::reverse_iterator<const_iterator_adjacent_nodes>;

  DirectedGraph() = default;
  DirectedGraph(std::initializer_list<T> init);

  template <typename Iter>
  DirectedGraph(Iter first, Iter last);

  template <typename Iter>
  void assign(Iter first, Iter last);

  void assign(std::initializer_list<T> init);

  DirectedGraph& operator=(std::initializer_list<T> init);

  std::pair<iterator, bool> insert(const T& node_value);
  std::pair<iterator, bool> insert(T&& node_value);

  iterator erase(const_iterator pos);
  iterator erase(const_iterator first, const_iterator last);

  bool insert_edge(const T& from_node_value, const T& to_node_value);
  bool erase_edge(const T& from_node_value, const T& to_node_value);

  // std::size_t size() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear() noexcept;

  bool empty() const noexcept;

  void swap(DirectedGraph& other) noexcept;

  std::set<T> get_adjacent_node_values(const T& node_value) const;

  bool operator==(const DirectedGraph& rhs) const;
  bool operator!=(const DirectedGraph& rhs) const;

  reference operator[](size_type index);
  const_reference operator[](size_type index) const;

  reference at(size_type index);
  const_reference at(size_type index) const;

  iterator begin() noexcept;
  iterator end() noexcept;

  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  reverse_iterator rbegin() noexcept;
  reverse_iterator rend() noexcept;

  const_reverse_iterator rbegin() const noexcept;
  const_reverse_iterator rend() const noexcept;

  const_reverse_iterator rcbegin() const noexcept;
  const_reverse_iterator rcend() const noexcept;

  iterator_adjacent_nodes begin(const T& node_value) noexcept;
  iterator_adjacent_nodes end(const T& node_value) noexcept;

  const_iterator_adjacent_nodes begin(const T& node_value) const noexcept;
  const_iterator_adjacent_nodes end(const T& node_value) const noexcept;

  const_iterator_adjacent_nodes cbegin(const T& node_value) const noexcept;
  const_iterator_adjacent_nodes cend(const T& node_value) const noexcept;

  reverse_iterator_adjacent_nodes rbegin(const T& node_value) noexcept;
  reverse_iterator_adjacent_nodes rend(const T& node_value) noexcept;
  const_reverse_iterator_adjacent_nodes rbegin(const T& node_value) const noexcept;
  const_reverse_iterator_adjacent_nodes rend(const T& node_value) const noexcept;
  const_reverse_iterator_adjacent_nodes crbegin(const T& node_value) const noexcept;
  const_reverse_iterator_adjacent_nodes crend(const T& node_value) const noexcept;

private:
  using nodes_container_type = std::vector<details::GraphNode<T>>;
  nodes_container_type nodes_;

  typename nodes_container_type::iterator find(const T& node_value);
  typename nodes_container_type::const_iterator find(const T& node_value) const;

  void remove_all_links_to(typename nodes_container_type::const_iterator node);

  std::set<T> get_adjacent_node_values(
      const typename details::GraphNode<T>::adjacency_list_type& indices) const;

};

template <typename DG>
class const_directed_graph_iterator {
public:
  using value_type = typename DG::value_type;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;
  using pointer = const value_type*;
  using reference = const value_type&;
  using iterator_type =
    typename DG::nodes_container_type::const_iterator;

  const_directed_graph_iterator() = default;
  const_directed_graph_iterator(iterator_type it, const DG* graph);

  reference operator*() const;
  pointer operator->() const;

  const_directed_graph_iterator& operator++();
  const_directed_graph_iterator operator++(int);

  const_directed_graph_iterator& operator--();
  const_directed_graph_iterator operator--(int);

  bool operator==(const const_directed_graph_iterator& rhs) const;
  bool operator!=(const const_directed_graph_iterator& rhs) const;

protected:
  friend class DirectedGraph<value_type>;

  iterator_type node_iterator_;
  const DG* graph_ = nullptr;

  void increment();
  void decrement();
};

template <typename DG>
class directed_graph_iterator : public const_directed_graph_iterator<DG> {
public:
  using value_type = typename DG::value_type;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;
  using pointer = value_type*;
  using reference = value_type&;
  using iterator_type = typename DG::nodes_container_type::iterator;

  directed_graph_iterator() = default;
  directed_graph_iterator(iterator_type it, const DG* graph);

  reference operator*();
  pointer operator->();

  directed_graph_iterator& operator++();
  directed_graph_iterator operator++(int);

  directed_graph_iterator& operator--();
  directed_graph_iterator operator--(int);
};

template<typename DG>
class const_adjacent_nodes_iterator {
public:
  using value_type = typename details::GraphNode<typename DG::value_type>::adjacency_list_type;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;
  using pointer = value_type*;
  using reference = value_type&;
  using iterator_type = typename details::GraphNode<typename DG::value_type>::adjacency_list_type::iterator;

  const_adjacent_nodes_iterator() = default;
  const_adjacent_nodes_iterator(iterator_type it, const DG* graph);

  reference operator*() const;
  pointer operator->() const;

  const_adjacent_nodes_iterator& operator++();
  const_adjacent_nodes_iterator operator++(int);

  const_adjacent_nodes_iterator& operator--();
  const_adjacent_nodes_iterator operator--(int);

  bool operator==(const const_adjacent_nodes_iterator& rhs) const;
  bool operator!=(const const_adjacent_nodes_iterator& rhs) const;

protected:
  friend class DirectedGraph<value_type>;

  iterator_type node_iterator_;
  const DG* graph_ = nullptr;

  void increment();
  void decrement();
};

template <typename DG>
class adjacent_nodes_iterator : public const_adjacent_nodes_iterator<DG> {
public:
  using value_type = typename details::GraphNode<typename DG::value_type>::adjacency_list_type;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;
  using pointer = value_type*;
  using reference = value_type&;
  using iterator_type = typename details::GraphNode<typename DG::value_type>::adjacency_list_type::iterator;

  adjacent_nodes_iterator() = default;
  adjacent_nodes_iterator(iterator_type it, const DG* graph);

  reference operator*();
  pointer operator->();

  adjacent_nodes_iterator& operator++();
  adjacent_nodes_iterator operator++(int);

  adjacent_nodes_iterator& operator--();
  adjacent_nodes_iterator operator--(int);
};

template <typename T>
std::wstring to_dot(const DirectedGraph<T>& graph, std::wstring_view graph_name);

template <typename T>
std::string to_dot(const DirectedGraph<T>& graph, std::string_view graph_name);

template <typename T>
void swap(DirectedGraph<T>& first, DirectedGraph<T>& second);

#include "DirectedGraph.inl"
#include "GraphIterators.inl"
#include "GraphHelpers.inl"
