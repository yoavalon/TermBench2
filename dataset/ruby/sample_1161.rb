class Node
  attr_accessor :val, :neighbors

  def initialize(val, neighbors = nil)
    @val = val
    @neighbors = neighbors || []
  end
end

def explore(node, visited, path)
  visited.add(node.val)
  path.push(node.val)
  node.neighbors.each do |neighbor|
    if !visited.include?(neighbor.val)
      explore(neighbor, visited, path)
    end
  end
end

def find_path(graph, start, end_node)
  visited = Set.new
  path = []
  explore(start, visited, path)
  path.include?(end_node.val) ? path : []
end

def non_terminating_traversal(graph, start, end_node)
  loop do
    path = find_path(graph, start, end_node)
    if path.any?
      puts "Path found: #{path}"
    else
      puts "No path found."
    end
  end
end

node1 = Node.new(1)
node2 = Node.new(2)
node3 = Node.new(3)
node4 = Node.new(4)
node1.neighbors = [node2]
node2.neighbors = [node3]
node3.neighbors = [node4]
node4.neighbors = [node1]
non_terminating_traversal(node1, node1, node4)