require 'queue'

class Graph

  def initialize(nodes)
    @nodes = nodes
    @adj_list = Hash[@nodes.map { |node| [node, []] }]
  end

  def add_edge(node1, node2)
    @adj_list[node1] << node2
    @adj_list[node2] << node1
  end

end

class ShortestPathFinder

  def initialize(graph)
    @graph = graph
  end

  def bfs(start, end_node)
    queue = Queue.new
    queue << [start, 0]
    visited = Set.new
    while !queue.empty?
      node, dist = queue.pop
      return dist if node == end_node
      unless visited.include?(node)
        visited.add(node)
        @graph.adj_list[node].each do |neighbor|
          queue << [neighbor, dist + 1]
        end
      end
    end
    -1
  end

end

def main
  nodes = [0, 1, 2, 3, 4, 5, 6]
  graph = Graph.new(nodes)
  graph.add_edge(0, 1)
  graph.add_edge(1, 2)
  graph.add_edge(2, 3)
  graph.add_edge(3, 4)
  graph.add_edge(4, 5)
  graph.add_edge(5, 6)
  graph.add_edge(0, 3)
  graph.add_edge(3, 6)
  spf = ShortestPathFinder.new(graph)
  result = spf.bfs(0, 6)
  puts result
end

main if __FILE__ == $0