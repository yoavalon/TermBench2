class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { Array.new(vertices, 0) }
  end

  def add_edge(u, v, weight)
    @graph[u][v] = weight
    @graph[v][u] = weight
  end

  def min_distance(dist, spt_set)
    min = Float::INFINITY
    min_index = 0
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
    (0...@V).each do |cout|
      u = min_distance(dist, spt_set)
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

def generate_sequence(n)
  g = Graph.new(n)
  (0...n).each do |i|
    ((i + 1)...n).each do |j|
      weight = (i - j).abs
      g.add_edge(i, j, weight)
    end
  end
  g
end

def find_shortest_path(graph, src, dest)
  path_lengths = graph.dijkstra(src)
  path_lengths[dest]
end

def main
  n = 10
  graph = generate_sequence(n)
  src = 0
  dest = n - 1
  result = find_shortest_path(graph, src, dest)
  puts "Shortest path from #{src} to #{dest}: #{result}"
end

main if __FILE__ == $0