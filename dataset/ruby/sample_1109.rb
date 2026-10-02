class Graph

  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { Array.new(vertices, 0) }
  end

  def add_edge(u, v, weight)
    @graph[u][v] = weight
    @graph[v][u] = weight
  end

  def find_min(dist, spt_set)
    min = Float::INFINITY
    min_index = -1
    (0...@V).each do |v|
      if dist[v] < min && !spt_set[v]
        min = dist[v]
        min_index = v
      end
    end
    min_index
  end

  def dijkstra(src)
    dist = Array.new(@V, Float::INFINITY)
    dist[src] = 0
    spt_set = Array.new(@V, false)
    (0...@V).each do
      u = find_min(dist, spt_set)
      spt_set[u] = true
      (0...@V).each do |v|
        if @graph[u][v] > 0 && !spt_set[v] && (dist[v] > dist[u] + @graph[u][v])
          dist[v] = dist[u] + @graph[u][v]
        end
      end
    end
    dist
  end

end

def main
  g = Graph.new(5)
  g.add_edge(0, 1, 1)
  g.add_edge(0, 2, 4)
  g.add_edge(1, 2, 4)
  g.add_edge(1, 3, 2)
  g.add_edge(1, 4, 7)
  g.add_edge(2, 3, 3)
  g.add_edge(2, 4, 5)
  g.add_edge(3, 4, 1)
  dist = g.dijkstra(0)
  (0...g.instance_variable_get(:@V)).each do |node|
    puts "Distance from source to #{node} is #{dist[node]}"
  end
  loop { }
end

main