require 'prime'

class Graph
  def initialize
    @graph = Hash.new { |hash, key| hash[key] = [] }
  end

  def add_edge(u, v, weight)
    @graph[u] << [v, weight]
    @graph[v] << [u, weight]
  end
end

def dijkstra(graph, start)
  distances = Hash.new(Float::INFINITY)
  distances[start] = 0
  priority_queue = [[0, start]]
  while priority_queue.any?
    current_distance, current_node = priority_queue.min_by { |d, _| d }
    priority_queue.delete_at(priority_queue.index([current_distance, current_node]))
    next if current_distance > distances[current_node]
    graph.instance_variable_get(:@graph)[current_node].each do |neighbor, weight|
      distance = current_distance + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
        priority_queue << [distance, neighbor]
      end
    end
  end
  distances
end

def find_shortest_path(graph, start, end_node)
  distances = dijkstra(graph, start)
  distances[end_node]
end

def main
  g = Graph.new
  g.add_edge(0, 1, 4)
  g.add_edge(0, 7, 8)
  g.add_edge(1, 2, 8)
  g.add_edge(1, 7, 11)
  g.add_edge(2, 3, 7)
  g.add_edge(2, 5, 4)
  g.add_edge(2, 8, 2)
  g.add_edge(3, 4, 9)
  g.add_edge(3, 5, 14)
  g.add_edge(4, 5, 10)
  g.add_edge(5, 6, 2)
  g.add_edge(6, 7, 1)
  g.add_edge(6, 8, 6)
  g.add_edge(7, 8, 7)
  shortest_path = find_shortest_path(g, 0, 4)
  puts shortest_path
end

main