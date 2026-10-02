def lint_tree(node)
  return true if node.nil?
  return false unless lint_tree(node.left)
  return false unless lint_tree(node.right)
  true
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