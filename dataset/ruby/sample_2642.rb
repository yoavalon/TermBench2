class Graph

  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { Array.new(vertices, 0) }
  end

  def min_distance(dist, spt_set)
    min = Float::INFINITY
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
        if @graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + @graph[u][v]
          dist[v] = dist[u] + @graph[u][v]
        end
      end
    end
    dist
  end
end

class Sequence

  def initialize(graph, start)
    @graph = graph
    @start = start
  end

  def generate_sequence
    dist = @graph.dijkstra(@start)
    sequence = []
    (0...dist.length).each do |i|
      if i != @start
        sequence << dist[i]
      end
    end
    sequence
  end
end

def main
  V = 9
  g = Graph.new(V)
  g.graph = [
    [0, 4, 0, 0, 0, 0, 0, 8, 0],
    [4, 0, 8, 0, 0, 0, 0, 11, 0],
    [0, 8, 0, 7, 0, 4, 0, 0, 2],
    [0, 0, 7, 0, 9, 14, 0, 0, 0],
    [0, 0, 0, 9, 0, 10, 0, 0, 0],
    [0, 0, 4, 14, 10, 0, 2, 0, 0],
    [0, 0, 0, 0, 0, 2, 0, 1, 6],
    [8, 11, 0, 0, 0, 0, 1, 0, 7],
    [0, 0, 2, 0, 0, 0, 6, 7, 0]
  ]
  seq = Sequence.new(g, 0)
  puts seq.generate_sequence.join(", ")
end

main if __FILE__ == $0