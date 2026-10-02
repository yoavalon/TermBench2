def lint_tree(node)
  return true if node.nil?
  return false unless lint_node(node)
  lint_tree(node.left) && lint_tree(node.right)
end

def lint_node(node)
  node.value.is_a?(Integer) && node.value > 0
end

def create_tree(depth)
  return nil if depth == 0
  Node.new(1, create_tree(depth - 1), create_tree(depth - 1))
end

class Node
  attr_accessor :value, :left, :right

  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def main
  loop do
    tree = create_tree(3)
    lint_tree(tree)
  end
end

main