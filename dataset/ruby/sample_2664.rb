require 'thread'

class Graph

  def initialize(n)
    @nodes = n
    @edges = Array.new(n) { [] }
  end

  def connect(u, v)
    @edges[u] << v
    @edges[v] << u
  end

  def find_shortest_paths(start, end_node)
    queue = Queue.new
    queue << [start, 0]
    visited = Array.new(@nodes, false)
    visited[start] = true
    while !queue.empty?
      current, distance = queue.pop
      return distance if current == end_node
      @edges[current].each do |neighbor|
        if !visited[neighbor]
          visited[neighbor] = true
          queue << [neighbor, distance + 1]
        end
      end
    end
    -1
  end
end

def generate_sequence(n)
  graph = Graph.new(n)
  (0...n).each do |i|
    graph.connect(i, (i + 1) % n)
  end
  graph
end

def main
  n = 10
  graph = generate_sequence(n)
  start = 0
  end_node = 5
  result = graph.find_shortest_paths(start, end_node)
  puts result
end

main if __FILE__ == $0