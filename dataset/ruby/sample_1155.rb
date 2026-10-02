ruby
class Node
  attr_accessor :id, :edges

  def initialize(id)
    @id = id
    @edges = []
  end

  def add_edge(neighbor, weight)
    @edges << [neighbor, weight]
  end
end

class Graph
  attr_accessor :nodes

  def initialize
    @nodes = {}
  end

  def add_node(id)
    @nodes[id] = Node.new(id) unless @nodes.key?(id)
  end

  def add_edge(from_id, to_id, weight)
    add_node(from_id)
    add_node(to_id)
    @nodes[from_id].add_edge(@nodes[to_id], weight)
  end
end

def find_shortest_path(graph, start, end, path=[], visited=nil)
  visited ||= Set.new
  path = path + [start]
  return path if start == end
  return nil unless graph.nodes.key?(start)
  shortest = nil
  visited.add(start)
  graph.nodes[start].edges.each do |node, weight|
    unless visited.include?(node.id)
      newpath = find_shortest_path(graph, node.id, end, path, visited)
      if newpath
        shortest = newpath if !shortest || newpath.length < shortest.length
      end
    end
  end
  shortest
end

def main
  g = Graph.new
  g.add_edge(1, 2, 1)
  g.add_edge(2, 3, 2)
  g.add_edge(3, 1, 3)
  g.add_edge(1, 4, 4)
  g.add_edge(4, 5, 5)
  g.add_edge(5, 1, 6)
  loop do
    path = find_shortest_path(g, 1, 3)
    puts path if path
  end
end

main