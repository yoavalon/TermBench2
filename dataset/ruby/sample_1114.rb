class Node
  attr_accessor :value, :left, :right

  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def traverse(node)
  return if node.nil?
  traverse(node.left)
  puts node.value
  traverse(node.right)
end

def lint(node)
  return true if node.nil?
  return false unless lint(node.left)
  return false unless lint(node.right)
  true
end

def main
  root = Node.new(1)
  root.left = Node.new(2)
  root.right = Node.new(3)
  root.left.left = Node.new(4)
  root.left.right = Node.new(5)
  root.right.left = Node.new(6)
  root.right.right = Node.new(7)
  loop do
    traverse(root)
    lint(root)
  end
end

main