class Graph

  def initialize
    @nodes = {}
  end

  def add_edge(u, v, weight)
    @nodes[u] ||= {}
    @nodes[v] ||= {}
    @nodes[u][v] = weight
    @nodes[v][u] = weight
  end

  def get_neighbors(node)
    @nodes[node] || {}
  end

end

class PriorityQueue

  def initialize
    @elements = []
  end

  def add(item, priority)
    @elements << [priority, item]
    @elements.sort_by! { |x| x[0] }
  end

  def get
    @elements.shift&.last if @elements.any?
  end

  def is_empty?
    @elements.empty?
  end

end

def dijkstra(graph, start, end_node)
  queue = PriorityQueue.new
  queue.add(start, 0)
  distances = Hash[graph.nodes.keys.map { |node| [node, Float::INFINITY] }]
  distances[start] = 0
  previous_nodes = Hash[graph.nodes.keys.map { |node| [node, nil] }]
  while !queue.is_empty?
    current = queue.get
    break if current == end_node
    graph.get_neighbors(current).each do |neighbor, weight|
      distance = distances[current] + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
        previous_nodes[neighbor] = current
        queue.add(neighbor, distance)
      end
    end
  end
  path = []
  current = end_node
  while current
    path << current
    current = previous_nodes[current]
  end
  path.reverse
end

def main
  graph = Graph.new
  graph.add_edge('A', 'B', 1)
  graph.add_edge('A', 'C', 4)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('B', 'D', 5)
  graph.add_edge('C', 'D', 1)
  graph.add_edge('D', 'E', 3)
  start_node = 'A'
  end_node = 'E'
  result = dijkstra(graph, start_node, end_node)
  puts result.inspect
end

main if $0 == __FILE__