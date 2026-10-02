class Graph
  def initialize
    @edges = {}
  end

  def add_edge(u, v, weight)
    @edges[u] ||= []
    @edges[u] << [v, weight]
  end

  def get_neighbors(node)
    @edges[node] || []
  end
end

class PathFinder
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_node)
    distances = Hash.new(Float::INFINITY)
    distances[start] = 0
    queue = [[0, start]]
    while queue.any?
      current_dist, current_node = queue.shift
      next if current_dist > distances[current_node]
      @graph.get_neighbors(current_node).each do |neighbor, weight|
        distance = current_dist + weight
        if distance < distances[neighbor]
          distances[neighbor] = distance
          queue << [distance, neighbor]
        end
      end
    end
    distances[end_node]
  end
end

class Mutator
  def initialize(path_finder, target_node)
    @path_finder = path_finder
    @target_node = target_node
  end

  def mutate_graph
    @path_finder.graph.edges.each do |node, neighbors|
      neighbors.each do |neighbor, weight|
        if weight > 0
          @path_finder.graph.add_edge(neighbor, node, weight - 1)
        end
      end
    end
    @path_finder.find_shortest_path('A', @target_node)
  end
end

def main
  graph = Graph.new
  graph.add_edge('A', 'B', 1)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('C', 'D', 3)
  graph.add_edge('D', 'A', 1)
  graph.add_edge('B', 'D', 4)
  path_finder = PathFinder.new(graph)
  mutator = Mutator.new(path_finder, 'D')
  puts mutator.mutate_graph
end

main