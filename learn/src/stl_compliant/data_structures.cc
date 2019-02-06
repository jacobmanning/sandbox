#include <iostream>

#include "DirectedGraph.hh"

int main() {
  auto graph = DirectedGraph<int>();

  graph.insert(11);
  graph.insert(22);
  graph.insert(33);
  graph.insert(44);
  graph.insert(55);

  graph.insert_edge(11, 33);
  graph.insert_edge(22, 33);
  graph.insert_edge(22, 44);
  graph.insert_edge(22, 55);
  graph.insert_edge(33, 44);
  graph.insert_edge(44, 55);

  // std::wcout << to_dot(graph, L"Graph1") << std::endl;
  // std::cout << to_dot(graph, "Graph1") << std::endl;

  graph.erase_edge(22, 44);
  // TODO: Fix this deprecated function
  // graph.erase(44);
  // std::wcout << to_dot(graph, L"Graph1") << std::endl;
  // std::cout << to_dot(graph, "Graph1") << std::endl;

  // std::string version
  auto graph_s = DirectedGraph<std::string>();

  graph_s.insert("String 1");
  auto s = std::string{"String 2"};
  graph_s.insert(s);
  graph_s.insert("String 3");
  graph_s.insert("String 4");

  graph_s.insert_edge("String 1", s);
  graph_s.insert_edge("String 2", s);
  graph_s.insert_edge("String 3", s);

  // std::cout << to_dot(graph_s, "String Graph") << std::endl;
}
