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
      u = min_distance(dist, spt_set)
      spt_set[u] = true
      (0...@V).each do |v|
        if @graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + @graph[u][v]
          dist[v] = dist[u] + @graph[u][v]
        end
      end
    end
    dist
  end

end

class PathFinder

  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_vertex)
    distances = @graph.dijkstra(start)
    distances[end_vertex]
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
  path_finder = PathFinder.new(g)
  result = path_finder.find_shortest_path(0, 4)
  puts result
end

main if __FILE__ == $0