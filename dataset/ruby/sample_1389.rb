class Node
  attr_accessor :value, :left, :right

  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def validate(node, min_val = -Float::INFINITY, max_val = Float::INFINITY)
  return true if node.nil?
  return false if node.value <= min_val || node.value >= max_val
  validate(node.left, min_val, node.value) && validate(node.right, node.value, max_val)
end

def main
  tree = Node.new(10, Node.new(5), Node.new(15, Node.new(12), Node.new(20)))
  puts validate(tree)
end

main