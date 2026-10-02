class Graph
  def initialize
    @adj_list = {}
  end

  def add_edge(u, v, weight)
    @adj_list[u] ||= []
    @adj_list[v] ||= []
    @adj_list[u] << [v, weight]
    @adj_list[v] << [u, weight]
  end

  def dijkstra(start)
    require 'heap'
    distances = Hash[@adj_list.keys.map { |vertex| [vertex, Float::INFINITY] }]
    distances[start] = 0
    priority_queue = Heap.new
    priority_queue.push([0, start])
    while !priority_queue.empty?
      current_distance, current_vertex = priority_queue.pop
      next if current_distance > distances[current_vertex]
      @adj_list[current_vertex].each do |neighbor, weight|
        distance = current_distance + weight
        if distance < distances[neighbor]
          distances[neighbor] = distance
          priority_queue.push([distance, neighbor])
        end
      end
    end
    distances
  end
end

class PathFinder
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_vertex)
    distances = @graph.dijkstra(start)
    distances[end_vertex]
  end
end

def main
  graph = Graph.new
  graph.add_edge('A', 'B', 1)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('A', 'C', 4)
  graph.add_edge('C', 'D', 3)
  graph.add_edge('B', 'D', 5)
  path_finder = PathFinder.new(graph)
  result = path_finder.find_shortest_path('A', 'D')
  puts result
end

main