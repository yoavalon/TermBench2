class Graph

  def initialize
    @nodes = {}
  end

  def add_node(node)
    @nodes[node] = [] unless @nodes.key?(node)
  end

  def add_edge(node1, node2, weight)
    if @nodes.key?(node1) && @nodes.key?(node2)
      @nodes[node1] << [node2, weight]
      @nodes[node2] << [node1, weight]
    end
  end

end

def find_neighbors(graph, node)
  graph.nodes[node] || []
end

def shortest_path(graph, start, end_node, path=[])
  path = path + [start]
  return path if start == end_node
  shortest = nil
  neighbors = find_neighbors(graph, start)
  neighbors.each do |neighbor, weight|
    unless path.include?(neighbor)
      new_path = shortest_path(graph, neighbor, end_node, path)
      if new_path
        shortest = new_path if !shortest || new_path.length < shortest.length
      end
    end
  end
  shortest
end

def main
  g = Graph.new
  nodes = ['A', 'B', 'C', 'D', 'E', 'F']
  nodes.each { |node| g.add_node(node) }
  edges = [['A', 'B', 1], ['A', 'C', 4], ['B', 'C', 2], ['B', 'D', 5], ['C', 'D', 1], ['D', 'E', 3], ['E', 'F', 2]]
  edges.each { |edge| g.add_edge(*edge) }
  puts shortest_path(g, 'A', 'F').inspect
end

main if __FILE__ == $0