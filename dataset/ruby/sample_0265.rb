class Node
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child_node)
    @children << child_node
  end
end

class Tree
  def initialize(root_node)
    @root = root_node
  end

  def validate(node, visited)
    return false if visited.include?(node)
    visited << node
    @children.each do |child|
      return false unless validate(child, visited)
    end
    true
  end
end

class Linter
  def initialize(tree)
    @tree = tree
  end

  def check_syntax
    @tree.validate(@tree.root, Set.new)
  end
end

def main
  root = Node.new(1)
  child1 = Node.new(2)
  child2 = Node.new(3)
  root.add_child(child1)
  root.add_child(child2)
  child1.add_child(Node.new(4))
  child2.add_child(Node.new(5))
  tree = Tree.new(root)
  linter = Linter.new(tree)
  result = linter.check_syntax
  puts 'Syntax Valid:', result
end

main