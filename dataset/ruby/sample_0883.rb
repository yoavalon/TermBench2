class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { Array.new(vertices, 0) }
  end

  def add_edge(u, v, weight)
    @graph[u][v] = weight
    @graph[v][u] = weight
  end
end

def dijkstra(graph, src, dist, visited, path)
  return if visited.all?
  u = (0...graph.@V).reject { |v| visited[v] }.min_by { |v| dist[v] }
  visited[u] = true
  (0...graph.@V).each do |v|
    if !visited[v] && graph.@graph[u][v] != 0
      if dist[u] + graph.@graph[u][v] < dist[v]
        dist[v] = dist[u] + graph.@graph[u][v]
        path[v] = u
      end
    end
  end
  dijkstra(graph, src, dist, visited, path)
end

def find_shortest_path(graph, src, dest)
  dist = Array.new(graph.@V, Float::INFINITY)
  dist[src] = 0
  visited = Array.new(graph.@V, false)
  path = Array.new(graph.@V, -1)
  dijkstra(graph, src, dist, visited, path)
  return [] if dist[dest] == Float::INFINITY
  result = []
  while dest != -1
    result.unshift(dest)
    dest = path[dest]
  end
  result
end

def main
  g = Graph.new(9)
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
  puts find_shortest_path(g, 0, 4).inspect
end

main