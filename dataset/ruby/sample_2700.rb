class Graph
  def initialize
    @nodes = {}
  end

  def add_node(node)
    @nodes[node] = []
  end

  def add_edge(node1, node2, weight)
    if @nodes.key?(node1) && @nodes.key?(node2)
      @nodes[node1] << [node2, weight]
      @nodes[node2] << [node1, weight]
    end
  end
end

class PathFinder
  def initialize(graph)
    @graph = graph
  end

  def find_shortest_path(start, end_node)
    queue = [[start, 0]]
    visited = Set.new
    paths = {start => []}
    while queue.any?
      node, distance = queue.shift
      if node == end_node
        return paths[node] + [node]
      end
      if !visited.include?(node)
        visited.add(node)
        @graph.nodes[node].each do |neighbor, weight|
          if !visited.include?(neighbor)
            queue << [neighbor, distance + weight]
            paths[neighbor] = paths[node] + [node]
          end
        end
      end
    end
    []
  end
end

def main
  g = Graph.new
  g.add_node('A')
  g.add_node('B')
  g.add_node('C')
  g.add_node('D')
  g.add_node('E')
  g.add_node('F')
  g.add_node('G')
  g.add_edge('A', 'B', 1)
  g.add_edge('A', 'C', 4)
  g.add_edge('B', 'C', 2)
  g.add_edge('B', 'D', 5)
  g.add_edge('C', 'D', 1)
  g.add_edge('C', 'E', 3)
  g.add_edge('D', 'E', 1)
  g.add_edge('D', 'F', 8)
  g.add_edge('E', 'F', 2)
  g.add_edge('E', 'G', 2)
  g.add_edge('F', 'G', 7)
  pf = PathFinder.new(g)
  path = pf.find_shortest_path('A', 'G')
  puts path.inspect
end

main