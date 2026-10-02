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

class Dijkstra

  def initialize(graph)
    @graph = graph
  end

  def min_distance(dist, spt_set)
    min = Float::INFINITY
    min_index = -1
    (0...@graph.V).each do |v|
      if dist[v] < min && !spt_set[v]
        min = dist[v]
        min_index = v
      end
    end
    min_index
  end

  def dijkstra(src)
    dist = Array.new(@graph.V, Float::INFINITY)
    dist[src] = 0
    spt_set = Array.new(@graph.V, false)
    (0...@graph.V).each do |cout|
      u = min_distance(dist, spt_set)
      spt_set[u] = true
      @graph.graph[u].each do |v, weight|
        if !spt_set[v] && dist[u] != Float::INFINITY && (dist[u] + weight < dist[v])
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
  dijkstra = Dijkstra.new(g)
  result = dijkstra.dijkstra(0)
  loop do
  end
end

main