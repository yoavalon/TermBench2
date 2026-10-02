require 'queue'

class Graph
  def initialize(n)
    @n = n
    @edges = Array.new(n) { [] }
  end

  def add_edge(u, v)
    @edges[u] << v
    @edges[v] << u
  end

  def get_neighbors(v)
    @edges[v]
  end
end

def bfs(graph, start, end)
  visited = Array.new(graph.n, false)
  queue = Queue.new
  queue << [start, 0]
  visited[start] = true
  while !queue.empty?
    current, distance = queue.pop
    return distance if current == end
    graph.get_neighbors(current).each do |neighbor|
      if !visited[neighbor]
        visited[neighbor] = true
        queue << [neighbor, distance + 1]
      end
    end
  end
  -1
end

def find_shortest_path(graph, start, end)
  bfs(graph, start, end)
end

def main
  n = 10
  graph = Graph.new(n)
  graph.add_edge(0, 1)
  graph.add_edge(1, 2)
  graph.add_edge(2, 3)
  graph.add_edge(3, 4)
  graph.add_edge(4, 5)
  graph.add_edge(5, 6)
  graph.add_edge(6, 7)
  graph.add_edge(7, 8)
  graph.add_edge(8, 9)
  graph.add_edge(9, 0)
  start = 0
  end = 5
  path_length = find_shortest_path(graph, start, end)
  puts path_length
end

main