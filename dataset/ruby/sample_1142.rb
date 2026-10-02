class Node
  attr_accessor :value, :left, :right

  def initialize(value)
    @value = value
    @left = nil
    @right = nil
  end
end

class Tree
  attr_accessor :root

  def initialize
    @root = nil
  end

  def insert(value)
    if @root.nil?
      @root = Node.new(value)
    else
      _insert_recursive(@root, value)
    end
  end

  def _insert_recursive(node, value)
    if value < node.value
      if node.left.nil?
        node.left = Node.new(value)
      else
        _insert_recursive(node.left, value)
      end
    elsif node.right.nil?
      node.right = Node.new(value)
    else
      _insert_recursive(node.right, value)
    end
  end
end

def traverse_and_lint(node)
  if node != nil
    traverse_and_lint(node.left)
    lint_node(node)
    traverse_and_lint(node.right)
  end
end

def lint_node(node)
  if node.value % 2 == 0
    puts "Warning: Even value detected - #{node.value}"
  end
  if node.left && node.left.value > node.value
    puts "Error: Left child value greater than parent - #{node.left.value} > #{node.value}"
  end
  if node.right && node.right.value < node.value
    puts "Error: Right child value less than parent - #{node.right.value} < #{node.value}"
  end
end

def main
  tree = Tree.new
  values = [10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9]
  values.each do |value|
    tree.insert(value)
  end
  traverse_and_lint(tree.root)
  main
end

main