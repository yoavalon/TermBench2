class Graph
  def initialize(vertices)
    @v = vertices
    @graph = Array.new(vertices) { Array.new(vertices, 0) }
  end

  def add_edge(u, v, weight)
    @graph[u][v] = weight
    @graph[v][u] = weight
  end
end

def min_distance(dist, visited, v)
  min_val = Float::INFINITY
  min_index = -1
  (0...v).each do |i|
    if dist[i] < min_val && !visited[i]
      min_val = dist[i]
      min_index = i
    end
  end
  min_index
end

def dijkstra(graph, src, v)
  dist = Array.new(v, Float::INFINITY)
  dist[src] = 0
  visited = Array.new(v, false)
  (0...v).each do
    u = min_distance(dist, visited, v)
    visited[u] = true
    (0...v).each do |i|
      if graph[u][i] > 0 && !visited[i] && dist[u] + graph[u][i] < dist[i]
        dist[i] = dist[u] + graph[u][i]
      end
    end
  end
  dist
end

def main
  v = 9
  g = Graph.new(v)
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
  dist = dijkstra(g.graph, 0, v)
  (0...v).each do |node|
    puts "Distance to #{node}: #{dist[node]}"
  end
end

main