class Graph

  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { [] }
  end

  def add_edge(u, v, w)
    @graph[u] << [v, w]
    @graph[v] << [u, w]
  end

end

class ShortestPath

  def initialize(graph)
    @graph = graph
    @dist = Array.new(graph.V) { Float::INFINITY }
    @parent = Array.new(graph.V) { -1 }
  end

  def bellman_ford(src)
    @dist[src] = 0
    (graph.V - 1).times do
      @graph.V.times do |u|
        @graph.graph[u].each do |v, weight|
          if @dist[u] != Float::INFINITY && @dist[u] + weight < @dist[v]
            @dist[v] = @dist[u] + weight
            @parent[v] = u
          end
        end
      end
    end
  end

  def get_shortest_path(dst)
    path = []
    return path if @dist[dst] == Float::INFINITY
    while dst != -1
      path << dst
      dst = @parent[dst]
    end
    path.reverse!
  end

end

def main
  V = 5
  graph = Graph.new(V)
  graph.add_edge(0, 1, 4)
  graph.add_edge(0, 2, 8)
  graph.add_edge(1, 2, 8)
  graph.add_edge(1, 3, 7)
  graph.add_edge(1, 4, 9)
  graph.add_edge(2, 3, 4)
  graph.add_edge(2, 4, 2)
  graph.add_edge(3, 4, 11)
  graph.add_edge(3, 0, 2)
  graph.add_edge(4, 0, 7)
  shortest_path_finder = ShortestPath.new(graph)
  shortest_path_finder.bellman_ford(0)
  path = shortest_path_finder.get_shortest_path(4)
  puts path.inspect
end

main