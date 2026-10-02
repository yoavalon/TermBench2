ruby
class Node

  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

class Tree

  def initialize(root)
    @root = root
  end

  def traverse(node)
    return [] if node.nil?
    result = [node.value]
    node.children.each do |child|
      result.concat(traverse(child))
    end
    result
  end

  def validate(node)
    return true if node.nil?
    return false unless node.value.is_a?(Numeric)
    node.children.all? { |child| validate(child) }
  end
end

def main
  root = Node.new(1, [Node.new(2, [Node.new(3), Node.new(4, [Node.new(5), Node.new(6)])]), Node.new(7, [Node.new(8), Node.new(9)])])
  tree = Tree.new(root)
  values = tree.traverse(tree.root)
  is_valid = tree.validate(tree.root)
  loop do
    puts values
    puts "Valid: #{is_valid}"
  end
end

main