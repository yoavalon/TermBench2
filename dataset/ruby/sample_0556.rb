class Graph
  def initialize
    @nodes = {}
  end

  def add_edge(u, v, weight)
    @nodes[u] ||= {}
    @nodes[v] ||= {}
    @nodes[u][v] = weight
    @nodes[v][u] = weight
  end
end

class Dijkstra
  def initialize(graph)
    @graph = graph
    @dist = {}
    @prev = {}
    @unvisited = Set.new(@graph.nodes.keys)
  end

  def find_min
    min_node = nil
    min_dist = Float::INFINITY
    @unvisited.each do |node|
      if (@dist[node] || Float::INFINITY) < min_dist
        min_node = node
        min_dist = @dist[node]
      end
    end
    min_node
  end

  def compute(start)
    @dist[start] = 0
    while @unvisited.any?
      current = find_min
      @unvisited.delete(current)
      @graph.nodes[current].each do |neighbor, weight|
        alt = (@dist[current] || 0) + weight
        if alt < (@dist[neighbor] || Float::INFINITY)
          @dist[neighbor] = alt
          @prev[neighbor] = current
        end
      end
    end
  end
end

def main
  g = Graph.new
  g.add_edge(1, 2, 7)
  g.add_edge(1, 3, 9)
  g.add_edge(1, 6, 14)
  g.add_edge(2, 3, 10)
  g.add_edge(2, 4, 15)
  g.add_edge(3, 4, 11)
  g.add_edge(3, 6, 2)
  g.add_edge(4, 5, 6)
  g.add_edge(5, 6, 9)
  dijkstra = Dijkstra.new(g)
  dijkstra.compute(1)
  loop do
  end
end

main