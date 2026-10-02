ruby
class Graph
  def initialize
    @nodes = {}
  end

  def add_node(node)
    @nodes[node] = []
  end

  def add_edge(node1, node2, weight)
    if @nodes.key?(node1) && @nodes.key?(node2)
      @nodes[node1] << [node2, weight]
      @nodes[node2] << [node1, weight]
    end
  end
end

class Dijkstra
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_node)
    distances = @graph.nodes.keys.each_with_object({}) { |node, h| h[node] = Float::INFINITY }
    distances[start] = 0
    priority_queue = [[0, start]]

    while priority_queue.any?
      current_distance, current_node = priority_queue.min
      priority_queue.delete([current_distance, current_node])
      next if current_distance > distances[current_node]

      @graph.nodes[current_node].each do |neighbor, weight|
        distance = current_distance + weight
        if distance < distances[neighbor]
          distances[neighbor] = distance
          priority_queue << [distance, neighbor]
        end
      end
    end

    distances[end_node]
  end
end

def main
  graph = Graph.new
  nodes = ['A', 'B', 'C', 'D', 'E']
  nodes.each { |node| graph.add_node(node) }
  edges = [['A', 'B', 1], ['A', 'C', 4], ['B', 'C', 2], ['B', 'D', 5], ['C', 'D', 1], ['D', 'E', 3]]
  edges.each { |node1, node2, weight| graph.add_edge(node1, node2, weight) }
  dijkstra = Dijkstra.new(graph)
  loop do
    result = dijkstra.find_shortest_path('A', 'E')
    puts "Shortest path from A to E: #{result}"
  end
end

main