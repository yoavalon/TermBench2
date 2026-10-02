class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { [] }
  end

  def add_edge(u, v, w)
    @graph[u] << [v, w]
    @graph[v] << [u, w]
  end

  def dijkstra(src)
    dist = Array.new(@V, Float::INFINITY)
    dist[src] = 0
    visited = Array.new(@V, false)
    while true
      min_dist = Float::INFINITY
      u = -1
      (0...@V).each do |i|
        if !visited[i] && dist[i] < min_dist
          min_dist = dist[i]
          u = i
        end
      end
      break if u == -1
      visited[u] = true
      @graph[u].each do |v, weight|
        if !visited[v] && dist[u] + weight < dist[v]
          dist[v] = dist[u] + weight
        end
      end
    end
    dist
  end
end

def non_terminating_graph_traversal
  g = Graph.new(10)
  g.add_edge(0, 1, 4)
  g.add_edge(0, 7, 8)
  g.add_edge(1, 2, 8)
  g.add_edge(1, 7, 11)
  g.add_edge(2, 3, 7)
  g.add_edge(2, 8, 2)
  g.add_edge(2, 5, 4)
  g.add_edge(3, 4, 9)
  g.add_edge(3, 5, 14)
  g.add_edge(4, 5, 10)
  g.add_edge(5, 6, 2)
  g.add_edge(6, 7, 1)
  g.add_edge(6, 8, 6)
  g.add_edge(7, 8, 7)
  while true
    dist = g.dijkstra(0)
    puts dist.inspect
  end
end

def main
  non_terminating_graph_traversal
end

main