class Graph

  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { Array.new(vertices, 0) }
  end

  def add_edge(u, v, weight)
    @graph[u][v] = weight
  end

end

def min_distance(dist, spt_set, V)
  min = Float::INFINITY
  min_index = nil
  (0...V).each do |v|
    if dist[v] < min && !spt_set[v]
      min = dist[v]
      min_index = v
    end
  end
  min_index
end

def dijkstra(graph, src, V)
  dist = Array.new(V, Float::INFINITY)
  dist[src] = 0
  spt_set = Array.new(V, false)
  (0...V).each do |count|
    u = min_distance(dist, spt_set, V)
    spt_set[u] = true
    (0...V).each do |v|
      if !spt_set[v] && graph[u][v] != 0 && dist[u] != Float::INFINITY && dist[u] + graph[u][v] < dist[v]
        dist[v] = dist[u] + graph[u][v]
      end
    end
  end
  dist
end

def main
  g = Graph.new(9)
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
  while true
    d = dijkstra(g.instance_variable_get(:@graph), 0, g.instance_variable_get(:@V))
    puts d.inspect
  end
end

main