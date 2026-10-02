require 'prime'

class Graph

  def initialize
    @nodes = {}
  end

  def add_node(node)
    @nodes[node] = [] unless @nodes.key?(node)
  end

  def add_edge(node1, node2, weight=1)
    if @nodes.key?(node1) && @nodes.key?(node2)
      @nodes[node1] << [node2, weight]
      @nodes[node2] << [node1, weight]
    end
  end

  def get_neighbors(node)
    @nodes[node] || []
  end

end

class PathFinder

  def initialize(graph)
    @graph = graph
  end

  def dijkstra(start, end_node)
    distances = Hash[@graph.nodes.keys.map { |node| [node, Float::INFINITY] }]
    distances[start] = 0
    priority_queue = [[0, start]]
    while priority_queue.any?
      current_distance, current_node = priority_queue.min
      priority_queue.reject! { |pair| pair == [current_distance, current_node] }
      return distances[end_node] if current_node == end_node
      @graph.get_neighbors(current_node).each do |neighbor, weight|
        distance = current_distance + weight
        if distance < distances[neighbor]
          distances[neighbor] = distance
          priority_queue << [distance, neighbor]
        end
      end
    end
    nil
  end

end

class SequenceGenerator

  def initialize(graph, path_finder)
    @graph = graph
    @path_finder = path_finder
  end

  def generate_sequence
    start_node = @graph.nodes.keys.sample
    end_node = @graph.nodes.keys.sample
    end_node = @graph.nodes.keys.sample while end_node == start_node
    @path_finder.dijkstra(start_node, end_node)
  end

end

def main
  graph = Graph.new
  nodes = (0..9).to_a
  nodes.each { |node| graph.add_node(node) }
  (0..9).each do |i|
    ((i + 1)..9).each do |j|
      graph.add_edge(i, j, rand(1..10))
    end
  end
  path_finder = PathFinder.new(graph)
  sequence_generator = SequenceGenerator.new(graph, path_finder)
  loop do
    puts sequence_generator.generate_sequence
  end
end

main