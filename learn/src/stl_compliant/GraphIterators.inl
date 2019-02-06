template <typename DG>
const_directed_graph_iterator<DG>::const_directed_graph_iterator(
    iterator_type it, const DG* graph) : node_iterator_{it}, graph_{graph} {}

template <typename DG>
typename const_directed_graph_iterator<DG>::reference
const_directed_graph_iterator<DG>::operator*() const {
  return node_iterator_->get();
}

template <typename DG>
typename const_directed_graph_iterator<DG>::pointer
const_directed_graph_iterator<DG>::operator->() const {
  return &(node_iterator_->get());
}

template <typename DG>
const_directed_graph_iterator<DG>&
const_directed_graph_iterator<DG>::operator++() {
  increment();
  return *this;
}

template <typename DG>
const_directed_graph_iterator<DG>
const_directed_graph_iterator<DG>::operator++(int) {
  auto old_it = *this;
  increment();
  return old_it;
}

template <typename DG>
const_directed_graph_iterator<DG>&
const_directed_graph_iterator<DG>::operator--() {
  decrement();
  return *this;
}

template <typename DG>
const_directed_graph_iterator<DG>
const_directed_graph_iterator<DG>::operator--(int) {
  auto old_it = *this;
  decrement();
  return old_it;
}

template <typename DG>
bool const_directed_graph_iterator<DG>::operator==(
const const_directed_graph_iterator& rhs) const {
  if (this->graph_ == nullptr || rhs.graph_ == nullptr) {
    return false;
  }

  return this->node_iterator_ == rhs.node_iterator_ && this->graph_ == rhs.graph_;
}

template <typename DG>
bool const_directed_graph_iterator<DG>::operator!=(
const const_directed_graph_iterator& rhs) const {
  return !(*this == rhs);
}

template <typename DG>
void const_directed_graph_iterator<DG>::increment() {
  ++node_iterator_;
}

template <typename DG>
void const_directed_graph_iterator<DG>::decrement() {
  --node_iterator_;
}

// template <typename DG>
// directed_graph_iterator<DG>::directed_graph_iterator(
//     iterator_type it, const DG* graph) : node_iterator_{it}, graph_{graph} {}

template <typename DG>
typename directed_graph_iterator<DG>::reference
directed_graph_iterator<DG>::operator*() {
  return const_cast<reference>(this->node_iterator_->get());
}

// template <typename DG>
// directed_graph_iterator<DG>&
// directed_graph_iterator<DG>::operator++() {
//   this->increment();
//   return *this;
// }

template <typename DG>
const_adjacent_nodes_iterator<DG>::const_adjacent_nodes_iterator(
    iterator_type it, const DG* graph) : node_iterator_{it}, graph_{graph} {}

template <typename DG>
typename const_adjacent_nodes_iterator<DG>::reference
const_adjacent_nodes_iterator<DG>::operator*() const {
  return node_iterator_->get();
}

template <typename DG>
typename const_adjacent_nodes_iterator<DG>::pointer
const_adjacent_nodes_iterator<DG>::operator->() const {
  return &(node_iterator_->get());
}

template <typename DG>
const_adjacent_nodes_iterator<DG>&
const_adjacent_nodes_iterator<DG>::operator++() {
  increment();
  return *this;
}

template <typename DG>
const_adjacent_nodes_iterator<DG>
const_adjacent_nodes_iterator<DG>::operator++(int) {
  auto old_it = *this;
  increment();
  return old_it;
}

template <typename DG>
const_adjacent_nodes_iterator<DG>&
const_adjacent_nodes_iterator<DG>::operator--() {
  decrement();
  return *this;
}

template <typename DG>
const_adjacent_nodes_iterator<DG>
const_adjacent_nodes_iterator<DG>::operator--(int) {
  auto old_it = *this;
  decrement();
  return old_it;
}

template <typename DG>
bool const_adjacent_nodes_iterator<DG>::operator==(
const const_adjacent_nodes_iterator& rhs) const {
  if (this->graph_ == nullptr || rhs.graph_ == nullptr) {
    return false;
  }

  return this->node_iterator_ == rhs.node_iterator_ && this->graph_ == rhs.graph_;
}

template <typename DG>
bool const_adjacent_nodes_iterator<DG>::operator!=(
const const_adjacent_nodes_iterator& rhs) const {
  return !(*this == rhs);
}

template <typename DG>
void const_adjacent_nodes_iterator<DG>::increment() {
  ++node_iterator_;
}

template <typename DG>
void const_adjacent_nodes_iterator<DG>::decrement() {
  --node_iterator_;
}

template <typename DG>
typename adjacent_nodes_iterator<DG>::reference
adjacent_nodes_iterator<DG>::operator*() {
  return const_cast<reference>(this->node_iterator_->get());
}
