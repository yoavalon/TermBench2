class Graph
  def initialize
    @adj_list = {}
  end

  def add_vertex(vertex)
    @adj_list[vertex] = [] unless @adj_list.key?(vertex)
  end

  def add_edge(vertex1, vertex2, weight)
    if @adj_list.key?(vertex1) && @adj_list.key?(vertex2)
      @adj_list[vertex1] << [vertex2, weight]
      @adj_list[vertex2] << [vertex1, weight]
    end
  end

  def get_neighbors(vertex)
    @adj_list[vertex] || []
  end
end

class Dijkstra
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_vertex)
    distances = @graph.adj_list.keys.each_with_object({}) { |vertex, hash| hash[vertex] = Float::INFINITY }
    distances[start] = 0
    priority_queue = [[0, start]]

    while priority_queue.any?
      current_distance, current_vertex = priority_queue.min
      priority_queue.reject! { |pair| pair == [current_distance, current_vertex] }
      next if current_distance > distances[current_vertex]

      @graph.get_neighbors(current_vertex).each do |neighbor, weight|
        distance = current_distance + weight
        if distance < distances[neighbor]
          distances[neighbor] = distance
          priority_queue << [distance, neighbor]
        end
      end
    end

    distances[end_vertex]
  end
end

def main
  g = Graph.new
  g.add_vertex('A')
  g.add_vertex('B')
  g.add_vertex('C')
  g.add_vertex('D')
  g.add_vertex('E')
  g.add_edge('A', 'B', 1)
  g.add_edge('B', 'C', 2)
  g.add_edge('C', 'D', 3)
  g.add_edge('D', 'E', 4)
  g.add_edge('A', 'E', 10)
  dijkstra = Dijkstra.new(g)
  result = dijkstra.find_shortest_path('A', 'E')
  puts result
end

main if __FILE__ == $0