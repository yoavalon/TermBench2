class Node
  attr_accessor :value, :children

  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end

  def add_child(child)
    @children << child
  end
end

class Tree
  attr_accessor :root

  def initialize(root)
    @root = root
  end

  def traverse
    result = []
    _traverse_helper(@root, result)
    result
  end

  def _traverse_helper(node, accumulator)
    return if node.nil?
    accumulator << node.value
    node.children.each do |child|
      _traverse_helper(child, accumulator)
    end
  end
end

class SemanticLint
  attr_accessor :tree

  def initialize(tree)
    @tree = tree
  end

  def check
    issues = []
    _check_helper(@tree.root, issues)
    issues
  end

  def _check_helper(node, issues)
    return if node.nil?
    if _is_floating_point(node.value)
      unless _has_high_precision(node.value)
        issues << "Low precision for #{node.value}"
      end
    end
    node.children.each do |child|
      _check_helper(child, issues)
    end
  end

  def _is_floating_point(value)
    Float(value)
    true
  rescue ArgumentError
    false
  end

  def _has_high_precision(value)
    (Float(value) - Float(value).round(10)).abs < 1e-09
  end
end

def main
  root = Node.new('1.0')
  child1 = Node.new('0.1')
  child2 = Node.new('0.0000000001')
  root.add_child(child1)
  root.add_child(child2)
  tree = Tree.new(root)
  lint = SemanticLint.new(tree)
  puts lint.check
end

main