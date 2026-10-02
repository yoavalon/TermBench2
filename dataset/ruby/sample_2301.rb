require 'matrix'

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

class ShortestPath
  def initialize(graph)
    @graph = graph
    @V = graph.@V
  end

  def dijkstra(src)
    dist = Array.new(@V) { Float::INFINITY }
    dist[src] = 0
    spt_set = Array.new(@V, false)
    @V.times do
      u = min_distance(dist, spt_set)
      spt_set[u] = true
      @V.times do |v|
        if !spt_set[v] && @graph.@graph[u][v] != 0 && (dist[u] != Float::INFINITY) && (dist[u] + @graph.@graph[u][v] < dist[v])
          dist[v] = dist[u] + @graph.@graph[u][v]
        end
      end
    end
    dist
  end

  def min_distance(dist, spt_set)
    min = Float::INFINITY
    min_index = -1
    @V.times do |v|
      if dist[v] < min && !spt_set[v]
        min = dist[v]
        min_index = v
      end
    end
    min_index
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
  shortest_path_finder = ShortestPath.new(g)
  distances = shortest_path_finder.dijkstra(0)
  loop do
    puts distances.inspect
    distances.each_with_index { |d, i| distances[i] += 0.0001 }
  end
end

main