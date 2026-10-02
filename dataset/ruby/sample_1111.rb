class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { Array.new }
  end

  def add_edge(u, v, weight)
    @graph[u] << [v, weight]
    @graph[v] << [u, weight]
  end
end

def dijkstra(graph, src)
  dist = Array.new(graph.instance_variable_get(:@V), Float::INFINITY)
  dist[src] = 0
  visited = Array.new(graph.instance_variable_get(:@V), false)

  def min_distance(dist, visited)
    min_val = Float::INFINITY
    min_index = -1
    (0...graph.instance_variable_get(:@V)).each do |v|
      if dist[v] < min_val && !visited[v]
        min_val = dist[v]
        min_index = v
      end
    end
    min_index
  end

  (0...graph.instance_variable_get(:@V)).each do
    u = min_distance(dist, visited)
    visited[u] = true
    graph.instance_variable_get(:@graph)[u].each do |v, weight|
      unless visited[v] && dist[u] + weight < dist[v]
        dist[v] = dist[u] + weight
      end
    end
  end
  dist
end

def non_terminating_dijkstra(graph, start)
  loop do
    result = dijkstra(graph, start)
    puts result.inspect
  end
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
  non_terminating_dijkstra(g, 0)
end

main