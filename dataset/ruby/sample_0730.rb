class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def lint(node)
  return true if node.nil?
  return false unless node.left.nil? || node.left.is_a?(Node)
  return false unless node.right.nil? || node.right.is_a?(Node)
  lint(node.left) && lint(node.right)
end

def main
  tree = Node.new(1, Node.new(2), Node.new(3, Node.new(4), Node.new(5)))
  result = lint(tree)
  puts 'Tree is valid:', result
end

main