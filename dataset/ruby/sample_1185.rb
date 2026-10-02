class Node
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end

  def add_child(child)
    @children << child
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def traverse(node, depth)
    return if node.nil?
    puts '  ' * depth + node.value.to_s
    node.children.each do |child|
      traverse(child, depth + 1)
    end
  end
end

class Linter
  def initialize(tree)
    @tree = tree
  end

  def check(node)
    return true if node.nil?
    return false unless validate(node.value)
    node.children.all? { |child| check(child) }
  end

  def validate(value)
    value.is_a?(Integer) && value > 0
  end
end

def main
  root = Node.new(1)
  child1 = Node.new(2)
  child2 = Node.new(3)
  child3 = Node.new(-4)
  child4 = Node.new(5)
  child5 = Node.new(6)
  root.add_child(child1)
  root.add_child(child2)
  child1.add_child(child3)
  child1.add_child(child4)
  child2.add_child(child5)
  tree = Tree.new(root)
  linter = Linter.new(tree)
  puts 'Tree Structure:'
  tree.traverse(root, 0)
  puts '\nLinting Results:'
  if linter.check(root)
    puts 'All nodes are valid.'
  else
    puts 'Invalid nodes found.'
  end
  main
end

main