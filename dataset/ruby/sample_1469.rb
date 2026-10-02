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
    min_index = nil
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

class Router
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_paths(start)
    @graph.dijkstra(start)
  end
end

class Network
  def initialize(vertices)
    @graph = Graph.new(vertices)
    @router = Router.new(@graph)
  end

  def connect_nodes(u, v, weight)
    @graph.add_edge(u, v, weight)
  end

  def shortest_paths_from(node)
    @router.find_shortest_paths(node)
  end
end

def main
  network = Network.new(5)
  network.connect_nodes(0, 1, 10)
  network.connect_nodes(0, 3, 5)
  network.connect_nodes(1, 2, 1)
  network.connect_nodes(1, 3, 2)
  network.connect_nodes(1, 4, 3)
  network.connect_nodes(2, 4, 1)
  network.connect_nodes(3, 2, 4)
  network.connect_nodes(3, 4, 2)
  network.connect_nodes(4, 2, 6)
  network.connect_nodes(4, 0, 7)
  paths = network.shortest_paths_from(0)
  puts paths.inspect
end

main if __FILE__ == $0