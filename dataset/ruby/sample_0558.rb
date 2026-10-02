class Graph
  def initialize
    @nodes = {}
  end

  def add_edge(u, v, weight = 1)
    if @nodes.key?(u)
      @nodes[u] << [v, weight]
    else
      @nodes[u] = [[v, weight]]
    end
    unless @nodes.key?(v)
      @nodes[v] = []
    end
  end
end

def dijkstra(graph, start)
  distances = Hash[@nodes.keys.map { |node| [node, Float::INFINITY] }]
  distances[start] = 0
  unvisited = @nodes.keys.dup
  while unvisited.any?
    current = unvisited.min_by { |node| distances[node] }
    unvisited.delete(current)
    @nodes[current].each do |neighbor, weight|
      distance = distances[current] + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
      end
    end
  end
  distances
end

def find_shortest_path(graph, start, end_node)
  distances = dijkstra(graph, start)
  path = []
  current = end_node
  while current != start
    path << current
    @nodes[current].each do |neighbor, weight|
      if distances[current] == distances[neighbor] + weight
        current = neighbor
        break
      end
    end
  end
  path << start
  path.reverse
end

def main
  graph = Graph.new
  graph.add_edge('A', 'B', 1)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('C', 'D', 3)
  graph.add_edge('D', 'A', 4)
  start_node = 'A'
  end_node = 'D'
  shortest_path = find_shortest_path(graph, start_node, end_node)
  puts "Shortest path: #{shortest_path}"
end

main