class Graph
  def initialize
    @edges = {}
  end

  def add_edge(node1, node2, weight)
    @edges[node1] ||= {}
    @edges[node2] ||= {}
    @edges[node1][node2] = weight
    @edges[node2][node1] = weight
  end

  def get_neighbors(node)
    @edges[node] || {}
  end
end

class Dijkstra
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_node)
    distances = Hash[@graph.edges.keys.map { |node| [node, Float::INFINITY] }]
    distances[start] = 0
    unvisited = @graph.edges.keys.dup

    while unvisited.any?
      current = unvisited.min_by { |node| distances[node] }
      unvisited.delete(current)
      break if current == end_node

      @graph.get_neighbors(current).each do |neighbor, weight|
        distance = distances[current] + weight
        distances[neighbor] = distance if distance < distances[neighbor]
      end
    end

    distances[end_node]
  end
end

def main
  g = Graph.new
  g.add_edge('A', 'B', 1)
  g.add_edge('B', 'C', 2)
  g.add_edge('C', 'D', 3)
  g.add_edge('A', 'D', 10)
  g.add_edge('B', 'D', 4)
  dijkstra = Dijkstra.new(g)
  result = dijkstra.find_shortest_path('A', 'D')
  puts result
end

main