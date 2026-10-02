class Graph
  def initialize
    @nodes = {}
  end

  def add_node(node)
    @nodes[node] = [] unless @nodes.key?(node)
  end

  def add_edge(from_node, to_node, weight)
    @nodes[from_node] << [to_node, weight] if @nodes.key?(from_node)
  end
end

def dijkstra(graph, start, end_node)
  distances = @nodes.keys.each_with_object({}) { |node, hash| hash[node] = Float::INFINITY }
  distances[start] = 0
  priority_queue = [[0, start]]
  while priority_queue.any?
    current_distance, current_node = priority_queue.min_by { |dist, _| dist }
    priority_queue.delete([current_distance, current_node])
    next if current_distance > distances[current_node]
    @nodes[current_node].each do |neighbor, weight|
      distance = current_distance + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
        priority_queue << [distance, neighbor]
      end
    end
  end
  distances[end_node]
end

def main
  graph = Graph.new
  graph.add_node(1)
  graph.add_node(2)
  graph.add_node(3)
  graph.add_node(4)
  graph.add_edge(1, 2, 10)
  graph.add_edge(1, 3, 15)
  graph.add_edge(2, 3, 7)
  graph.add_edge(2, 4, 12)
  graph.add_edge(3, 4, 10)
  puts dijkstra(graph, 1, 4)
end

main