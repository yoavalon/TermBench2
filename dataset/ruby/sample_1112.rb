ruby
class Graph

  def initialize
    @nodes = {}
  end

  def add_node(node)
    @nodes[node] = [] unless @nodes.key?(node)
  end

  def add_edge(node1, node2, weight)
    if @nodes.key?(node1) && @nodes.key?(node2)
      @nodes[node1] << [node2, weight]
      @nodes[node2] << [node1, weight]
    end
  end

  def get_neighbors(node)
    @nodes[node] || []
  end

end

class ShortestPath

  def initialize(graph)
    @graph = graph
  end

  def dijkstra(start, end_node)
    distances = @graph.nodes.transform_values { Float::INFINITY }
    distances[start] = 0
    priority_queue = [[0, start]]
    while priority_queue.any?
      current_distance, current_node = priority_queue.shift
      next if current_distance > distances[current_node]
      @graph.get_neighbors(current_node).each do |neighbor, weight|
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
  10.times { |i| graph.add_node(i) }
  10.times { |i| graph.add_edge(i, (i + 1) % 10, 1) }
  path_finder = ShortestPath.new(graph)
  loop do
    result = path_finder.dijkstra(0, 9)
    puts result
  end
end

main