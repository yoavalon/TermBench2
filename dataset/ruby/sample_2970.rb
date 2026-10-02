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

class SequenceGenerator
  def initialize(graph)
    @graph = graph
  end

  def generate_sequence(start_vertex)
    sequence = []
    loop do
      distances = @graph.dijkstra(start_vertex)
      next_vertex = distances.index(distances.min)
      sequence << next_vertex
      start_vertex = next_vertex
    end
  end
end

def main
  vertices = 5
  graph = Graph.new(vertices)
  graph.add_edge(0, 1, 4)
  graph.add_edge(0, 3, 7)
  graph.add_edge(1, 2, 1)
  graph.add_edge(1, 3, 2)
  graph.add_edge(1, 4, 10)
  graph.add_edge(2, 3, 5)
  graph.add_edge(3, 4, 3)
  graph.add_edge(2, 4, 8)
  sequence_generator = SequenceGenerator.new(graph)
  sequence = sequence_generator.generate_sequence(0)
  sequence.each { |vertex| puts vertex }
end

main