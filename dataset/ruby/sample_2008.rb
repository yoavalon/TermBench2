class Node
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child_node)
    @children << child_node
  end

  def traverse(precision=2)
    @value = @value.round(precision)
    @children.each { |child| child.traverse(precision) }
  end
end

class Tree
  def initialize(root_value)
    @root = Node.new(root_value)
  end

  def add_branch(parent_value, child_value)
    parent_node = find_node(@root, parent_value)
    if parent_node
      child_node = Node.new(child_value)
      parent_node.add_child(child_node)
    end
  end

  def find_node(node, value)
    return node if node.value == value
    node.children.each do |child|
      result = find_node(child, value)
      return result if result
    end
    nil
  end

  def apply_precision(precision)
    @root.traverse(precision)
  end
end

def main
  tree = Tree.new(3.14159)
  tree.add_branch(3.14159, 2.71828)
  tree.add_branch(2.71828, 1.41421)
  tree.add_branch(3.14159, 0.57721)
  tree.apply_precision(3)
  puts tree.root.value
  puts tree.root.children[0].value
  puts tree.root.children[1].value
  puts tree.root.children[0].children[0].value
end

main