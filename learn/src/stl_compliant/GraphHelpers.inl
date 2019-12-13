// template <typename T>
// std::wstring to_dot(const DirectedGraph<T>& graph, std::wstring_view graph_name) {
//   auto wss = std::wstringstream{};
//
//   wss << "Digraph " << graph_name << " {" << std::endl;
//   for (std::size_t index = 0; index < graph.size(); ++index) {
//     const auto& node_value = graph[index];
//     const auto adjacent_nodes = graph.get_adjacent_node_values(node_value);
//
//     if (adjacent_nodes.empty()) {
//       wss << node_value << std::endl;
//     } else {
//       for (auto&& node : adjacent_nodes) {
//         wss << node_value << " -> " << node << std::endl;
//       }
//     }
//   }
//
//   wss << "}" << std::endl;
//   return wss.str();
// }
//
// template <typename T>
// std::string to_dot(const DirectedGraph<T>& graph, std::string_view graph_name) {
//   auto ss = std::stringstream{};
//
//   ss << "Digraph " << graph_name << " {" << std::endl;
//   for (auto&& node : graph) {
//     const auto b = graph.cbegin(node);
//     const auto e = graph.cend(node);
//
//     if (b == e) {
//       ss << node << std::endl;
//     } else {
//       for (auto iter = b; iter != e; ++iter) {
//         ss << node << " -> " << *iter << std::endl;
//       }
//     }
//   }
//
//   ss << "}" << std::endl;
//   return ss.str();
// }
//
template <typename T>
void swap(DirectedGraph<T>& first, DirectedGraph<T>& second)
{
  first.swap(second);
}
