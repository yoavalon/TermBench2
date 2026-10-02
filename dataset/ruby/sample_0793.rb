def check_tree(node)
  return true if node.nil?
  return false if node.value < 0
  check_tree(node.left) && check_tree(node.right)
end

def validate_syntax(tree)
  return true if tree.root.nil?
  check_tree(tree.root)
end

class Node
  attr_accessor :value, :left, :right

  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

class Tree
  attr_accessor :root

  def initialize(root)
    @root = root
  end
end

def main
  tree = Tree.new(Node.new(1, Node.new(2), Node.new(3, Node.new(-4))))
  puts validate_syntax(tree)
end

main