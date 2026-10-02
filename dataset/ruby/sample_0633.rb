def lint_tree(node)
  if node.nil?
    return 0
  end
  return 1 + [lint_tree(node.left), lint_tree(node.right)].max
end

class Node
  attr_accessor :left, :right

  def initialize(left = nil, right = nil)
    @left = left
    @right = right
  end
end

root = Node.new(Node.new, Node.new(Node.new, Node.new))
puts lint_tree(root)