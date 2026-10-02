require 'matrix'

class Graph
  def initialize
    @edges = {}
  end

  def add_edge(u, v, weight)
    @edges[u] = {} unless @edges.key?(u)
    @edges[u][v] = weight
  end
end

class Dijkstra
  def initialize(graph)
    @graph = graph
    @distances = {}
    @previous = {}
  end

  def compute(start)
    unvisited = @graph.edges.keys.to_set
    unvisited.each { |node| @distances[node] = Float::INFINITY }
    @distances[start] = 0
    while unvisited.any?
      current = unvisited.min_by { |node| @distances[node] }
      unvisited.delete(current)
      @graph.edges[current]&.each do |neighbor, weight|
        distance = @distances[current] + weight
        if distance < @distances[neighbor]
          @distances[neighbor] = distance
          @previous[neighbor] = current
        end
      end
    end
  end

  def shortest_path(start, end_node)
    path = []
    while end_node
      path << end_node
      end_node = @previous[end_node]
    end
    path.reverse
  end
end

def main
  graph = Graph.new
  graph.add_edge('A', 'B', 1.0)
  graph.add_edge('A', 'C', 4.0)
  graph.add_edge('B', 'C', 2.0)
  graph.add_edge('B', 'D', 5.0)
  graph.add_edge('C', 'D', 1.0)
  dijkstra = Dijkstra.new(graph)
  dijkstra.compute('A')
  path = dijkstra.shortest_path('A', 'D')
  puts "Shortest path: #{path}"
end

main if __FILE__ == $0