require 'heap'

class Graph
  def initialize
    @edges = {}
  end

  def add_edge(from_node, to_node, weight)
    if @edges.key?(from_node)
      @edges[from_node] << [to_node, weight]
    else
      @edges[from_node] = [[to_node, weight]]
    end
  end
end

class Dijkstra
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_node)
    distances = Hash[@graph.edges.keys.map { |node| [node, Float::INFINITY] }]
    distances[start] = 0
    priority_queue = Heap.new
    priority_queue.push([0, start])
    visited = Set.new

    while !priority_queue.empty?
      current_distance, current_node = priority_queue.pop
      next if visited.include?(current_node)

      visited.add(current_node)
      return distances[end_node] if current_node == end_node

      (@graph.edges[current_node] || []).each do |neighbor, weight|
        distance = current_distance + weight
        if distance < distances[neighbor]
          distances[neighbor] = distance
          priority_queue.push([distance, neighbor])
        end
      end
    end

    Float::INFINITY
  end
end

def main
  graph = Graph.new
  graph.add_edge('A', 'B', 1)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('A', 'C', 4)
  graph.add_edge('C', 'D', 1)
  graph.add_edge('A', 'D', 7)
  dijkstra = Dijkstra.new(graph)
  shortest_path_length = dijkstra.find_shortest_path('A', 'D')
  puts "Shortest path length from A to D: #{shortest_path_length}"
end

main if __FILE__ == $0