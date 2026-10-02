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

class PriorityQueue
  def initialize
    @elements = []
  end

  def empty?
    @elements.empty?
  end

  def put(item, priority)
    @elements << [priority, item]
    @elements.sort!
  end

  def get
    @elements.shift[1]
  end
end

def dijkstra(graph, start, end_vertex)
  queue = PriorityQueue.new
  queue.put(start, 0)
  distances = Hash.new(Float::INFINITY)
  distances[start] = 0
  previous = Hash.new(nil)

  until queue.empty?
    current = queue.get
    break if current == end_vertex

    graph.get_neighbors(current).each do |neighbor, weight|
      distance = distances[current] + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
        previous[neighbor] = current
        queue.put(neighbor, distance)
      end
    end
  end

  path = []
  while end_vertex
    path << end_vertex
    end_vertex = previous[end_vertex]
  end

  [path.reverse, distances]
end

def main
  graph = Graph.new
  vertices = ['A', 'B', 'C', 'D', 'E']
  vertices.each { |vertex| graph.add_vertex(vertex) }
  graph.add_edge('A', 'B', 1)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('C', 'D', 3)
  graph.add_edge('D', 'E', 4)
  graph.add_edge('E', 'A', 5)
  path, distances = dijkstra(graph, 'A', 'E')
  puts "Path: #{path}"
  puts "Distances: #{distances}"
end

main