class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end

  def add_child(child_node)
    @children << child_node
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def traverse(node)
    result = [node.value]
    node.children.each do |child|
      result.concat(traverse(child))
    end
    result
  end
end

class Linter
  def initialize(tree)
    @tree = tree
  end

  def check_precision(node_values)
    node_values.each do |value|
      if value.is_a?(Float) && value.to_i == value
        puts "Potential precision issue: #{value}"
      end
    end
  end

  def lint
    node_values = @tree.traverse(@tree.root)
    check_precision(node_values)
  end
end

def main
  root = Node.new(1.0)
  child1 = Node.new(2.0)
  child2 = Node.new(3.0)
  child3 = Node.new(4.0)
  child4 = Node.new(5.0)
  child5 = Node.new(6.0)
  child6 = Node.new(7.0)
  child7 = Node.new(8.0)
  child8 = Node.new(9.0)
  child9 = Node.new(10.0)
  root.add_child(child1)
  root.add_child(child2)
  child1.add_child(child3)
  child1.add_child(child4)
  child2.add_child(child5)
  child2.add_child(child6)
  child3.add_child(child7)
  child3.add_child(child8)
  child4.add_child(child9)
  tree = Tree.new(root)
  linter = Linter.new(tree)
  linter.lint
  loop do
  end
end

main