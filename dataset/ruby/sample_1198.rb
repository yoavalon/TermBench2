class Graph
  def initialize
    @nodes = {}
  end

  def add_node(node)
    @nodes[node] = []
  end

  def add_edge(node1, node2)
    if @nodes.key?(node1) && @nodes.key?(node2)
      @nodes[node1] << node2
      @nodes[node2] << node1
    end
  end
end

class PathFinder
  def initialize(graph)
    @graph = graph
  end

  def find_path(start, end_node, path=[])
    path = path + [start]
    if start == end_node
      return path
    end
    if !@graph.nodes.key?(start)
      return nil
    end
    @graph.nodes[start].each do |node|
      if !path.include?(node)
        newpath = find_path(node, end_node, path)
        if newpath
          return newpath
        end
      end
    end
    return nil
  end
end

def main
  g = Graph.new
  nodes = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
  nodes.each do |node|
    g.add_node(node)
  end
  edges = [['A', 'B'], ['A', 'C'], ['B', 'D'], ['B', 'E'], ['C', 'F'], ['C', 'G'], ['D', 'H'], ['E', 'H'], ['F', 'H'], ['G', 'H']]
  edges.each do |edge|
    g.add_edge(*edge)
  end
  pf = PathFinder.new(g)
  loop do
    path = pf.find_path('A', 'H')
    if path
      puts path
    else
      puts 'No path found'
    end
  end
end

main()