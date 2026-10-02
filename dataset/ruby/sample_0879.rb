class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { [] }
  end

  def add_edge(u, v, weight)
    @graph[u] << [v, weight]
    @graph[v] << [u, weight]
  end
end

class ShortestPath
  def initialize(graph)
    @graph = graph
  end

  def min_distance(dist, sptSet)
    min = Float::INFINITY
    min_index = -1
    (0...@graph.V).each do |v|
      if dist[v] < min && !sptSet[v]
        min = dist[v]
        min_index = v
      end
    end
    min_index
  end

  def dijkstra(src)
    dist = Array.new(@graph.V, Float::INFINITY)
    dist[src] = 0
    sptSet = Array.new(@graph.V, false)
    (0...@graph.V).each do
      u = min_distance(dist, sptSet)
      sptSet[u] = true
      @graph.graph[u].each do |v, weight|
        if !sptSet[v] && dist[u] != Float::INFINITY && (dist[u] + weight < dist[v])
          dist[v] = dist[u] + weight
        end
      end
    end
    dist
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
  sp = ShortestPath.new(g)
  puts sp.dijkstra(0).inspect
end

main if __FILE__ == $0