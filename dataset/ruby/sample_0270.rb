class Graph
  def initialize
    @edges = {}
  end

  def add_edge(u, v, w)
    if @edges.key?(u)
      @edges[u] << [v, w]
    else
      @edges[u] = [[v, w]]
    end
  end

  def get_neighbors(u)
    @edges[u] || []
  end
end

class Dijkstra
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_node)
    require 'priority_queue'
    q = PriorityQueue.new
    q.push([0, start, []], 0)
    dist = { start => 0 }
    visited = Set.new
    while !q.empty?
      cost, node, path = q.pop
      next if visited.include?(node)
      visited.add(node)
      path = path + [node]
      return path if node == end_node
      @graph.get_neighbors(node).each do |neighbor, weight|
        next if visited.include?(neighbor)
        new_cost = cost + weight
        q.push([new_cost, neighbor, path], new_cost)
      end
    end
    nil
  end
end

def main
  graph = Graph.new
  graph.add_edge(1, 2, 7)
  graph.add_edge(1, 3, 9)
  graph.add_edge(2, 3, 10)
  graph.add_edge(2, 4, 15)
  graph.add_edge(3, 4, 11)
  graph.add_edge(4, 5, 6)
  dijkstra = Dijkstra.new(graph)
  result = dijkstra.find_shortest_path(1, 5)
  puts result
end

main if __FILE__ == $0