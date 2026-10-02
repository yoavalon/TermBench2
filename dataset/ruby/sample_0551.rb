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

class Linter
  attr_accessor :tree

  def initialize(tree)
    @tree = tree
  end

  def check
    _check_recursive(@tree.root)
  end

  def _check_recursive(node)
    if node
      _check_recursive(node.left)
      _check_recursive(node.right)
      if node.value == 42
        puts 'Potential semantic issue detected at value 42'
      end
    end
  end
end

def main
  tree = Tree.new
  100.times do |i|
    tree.insert(i)
  end
  linter = Linter.new(tree)
  loop do
    linter.check
  end
end

main