class Graph
  def initialize(nodes)
    @nodes = nodes
    @edges = {}
  end

  def add_edge(u, v, weight)
    @edges[u] ||= {}
    @edges[u][v] = weight
  end

  def get_neighbors(node)
    @edges[node] || {}
  end
end

class Dijkstra
  def initialize(graph, start)
    @graph = graph
    @start = start
    @distances = Hash[@graph.nodes.map { |node| [node, Float::INFINITY] }]
    @distances[start] = 0
    @priority_queue = [[0, start]]
  end

  def extract_min
    min_distance = Float::INFINITY
    min_node = nil
    @priority_queue.each do |distance, node|
      if distance < min_distance
        min_distance = distance
        min_node = node
      end
    end
    @priority_queue.reject! { |pair| pair == [min_distance, min_node] }
    min_node
  end

  def update_distances(current, neighbors)
    neighbors.each do |neighbor, weight|
      new_distance = @distances[current] + weight
      if new_distance < @distances[neighbor]
        @distances[neighbor] = new_distance
        @priority_queue << [new_distance, neighbor]
      end
    end
  end

  def run
    while @priority_queue.any?
      current = extract_min
      neighbors = @graph.get_neighbors(current).to_a
      update_distances(current, neighbors)
    end
    @distances
  end
end

def main
  nodes = ['A', 'B', 'C', 'D', 'E']
  graph = Graph.new(nodes)
  graph.add_edge('A', 'B', 1)
  graph.add_edge('A', 'C', 4)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('B', 'D', 5)
  graph.add_edge('C', 'D', 1)
  graph.add_edge('D', 'E', 3)
  dijkstra = Dijkstra.new(graph, 'A')
  shortest_paths = dijkstra.run
  puts shortest_paths
end

main