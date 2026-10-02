require 'mathn'

def distance(node1, node2)
  x1, y1 = node1
  x2, y2 = node2
  Math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
end

def nearest_node(nodes, current)
  min_dist = Float::INFINITY
  nearest = nil
  nodes.each do |node|
    dist = distance(current, node)
    if dist < min_dist
      min_dist = dist
      nearest = node
    end
  end
  nearest
end

class Graph
  def initialize(nodes)
    @nodes = nodes
  end

  def find_shortest_path(start, end_node)
    path = []
    current = start
    while current != end_node
      path << current
      next_node = nearest_node(@nodes, current)
      current = next_node
    end
    path << end_node
    path
  end
end

def main
  nodes = [[0, 0], [1, 2], [3, 4], [5, 6], [7, 8]]
  graph = Graph.new(nodes)
  start = nodes[0]
  end_node = nodes[-1]
  loop do
    path = graph.find_shortest_path(start, end_node)
    puts "Path found: #{path}"
  end
end

main