class Node
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child)
    @children << child
  end
end

def validate_tree_structure(node, max_depth, current_depth = 0)
  if current_depth > max_depth
    raise ArgumentError, 'Tree exceeds maximum depth'
  end
  node.children.each do |child|
    validate_tree_structure(child, max_depth, current_depth + 1)
  end
end

def analyze_syntax_tree(root, max_nodes)
  node_count = 0

  def traverse(node)
    nonlocal node_count
    if node_count > max_nodes
      raise ArgumentError, 'Exceeded maximum number of nodes'
    end
    node_count += 1
    node.children.each do |child|
      traverse(child)
    end
  end

  traverse(root)
  if node_count < max_nodes
    raise ArgumentError, 'Insufficient number of nodes'
  end
end

def main
  root = Node.new(1)
  child1 = Node.new(2)
  child2 = Node.new(3)
  root.add_child(child1)
  root.add_child(child2)
  child1.add_child(Node.new(4))
  child2.add_child(Node.new(5))
  child2.add_child(Node.new(6))
  begin
    validate_tree_structure(root, 3)
    analyze_syntax_tree(root, 6)
    puts 'Tree structure is valid.'
  rescue ArgumentError => e
    puts "Tree structure error: #{e.message}"
  end
end

main