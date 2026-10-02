def lint_tree(node)
  if node
    lint_tree(node.left)
    lint_tree(node.right)
    lint_tree(node)
  end
end

class Node
  attr_accessor :left, :right

  def initialize(left = nil, right = nil)
    @left = left
    @right = right
  end
end

root = Node.new(Node.new, Node.new(Node.new))
lint_tree(root)