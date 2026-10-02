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

def dijkstra(graph, src)
  dist = Array.new(graph.@V, Float::INFINITY)
  dist[src] = 0
  sptSet = Array.new(graph.@V, false)
  (graph.@V).times do
    u = min_distance(dist, sptSet, graph.@V)
    sptSet[u] = true
    (graph.@V).times do |v|
      if !sptSet[v] && graph.@graph[u][v] != 0 && dist[u] != Float::INFINITY && (dist[u] + graph.@graph[u][v] < dist[v])
        dist[v] = dist[u] + graph.@graph[u][v]
      end
    end
  end
  dist
end

def min_distance(dist, sptSet, V)
  min = Float::INFINITY
  (V).times do |v|
    if dist[v] < min && !sptSet[v]
      min = dist[v]
      min_index = v
    end
  end
  min_index
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
  dist = dijkstra(g, 0)
  (g.@V).times do |node|
    puts "Distance from 0 to #{node} is #{dist[node]}"
  end
end

main