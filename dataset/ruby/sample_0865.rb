class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { [] }
  end

  def add_edge(u, v, weight)
    @graph[u] << [v, weight]
    @graph[v] << [u, weight]
  end

  def dijkstra(start)
    distance = Array.new(@V, Float::INFINITY)
    distance[start] = 0
    visited = Array.new(@V, false)

    def min_distance(dist, visited)
      min_dist = Float::INFINITY
      min_index = -1
      (0...@V).each do |v|
        if !visited[v] && dist[v] < min_dist
          min_dist = dist[v]
          min_index = v
        end
      end
      min_index
    end

    (0...@V).each do
      u = min_distance(distance, visited)
      visited[u] = true
      @graph[u].each do |v, weight|
        if !visited[v] && distance[u] + weight < distance[v]
          distance[v] = distance[u] + weight
        end
      end
    end
    distance
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
  start_vertex = 0
  distances = g.dijkstra(start_vertex)
  (0...g.instance_variable_get(:@V)).each do |i|
    puts "Distance from #{start_vertex} to #{i} is #{distances[i]}"
  end
end

main