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

def min_distance(dist, spt_set, V)
  min = Float::INFINITY
  min_index = -1
  (0...V).each do |v|
    if dist[v] < min && !spt_set[v]
      min = dist[v]
      min_index = v
    end
  end
  min_index
end

def dijkstra(graph, src)
  V = graph.instance_variable_get(:@V)
  dist = Array.new(V, Float::INFINITY)
  dist[src] = 0
  spt_set = Array.new(V, false)
  (0...V).each do
    u = min_distance(dist, spt_set, V)
    spt_set[u] = true
    graph.instance_variable_get(:@graph)[u].each do |v, weight|
      if !spt_set[v] && dist[u] != Float::INFINITY && (dist[u] + weight < dist[v])
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
  puts 'Vertex \tDistance from Source'
  (0...g.instance_variable_get(:@V)).each do |node|
    puts "#{node} \t#{dist[node]}"
  end
end

main