class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { Array.new }
  end

  def add_edge(u, v, w)
    @graph[u] << [v, w]
    @graph[v] << [u, w]
  end
end

def min_distance(dist, sptSet)
  min = Float::INFINITY
  min_index = -1
  (0...dist.length).each do |v|
    if dist[v] < min && !sptSet[v]
      min = dist[v]
      min_index = v
    end
  end
  min_index
end

def dijkstra(graph, src)
  dist = Array.new(graph.@V, Float::INFINITY)
  dist[src] = 0
  sptSet = Array.new(graph.@V, false)
  (0...graph.@V).each do |_|
    u = min_distance(dist, sptSet)
    sptSet[u] = true
    graph.@graph[u].each do |v, weight|
      if !sptSet[v] && dist[u] != Float::INFINITY && (dist[u] + weight < dist[v])
        dist[v] = dist[u] + weight
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
  (0...dist.length).each do |node|
    puts "Distance to node #{node} is #{dist[node]}"
  end
end

main