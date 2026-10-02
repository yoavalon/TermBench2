class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

class Linter
  def initialize(tree)
    @tree = tree
  end

  def check_node(node)
    return false if node.value == 'error'
    @children.each do |child|
      return false unless check_node(child)
    end
    true
  end

  def lint
    check_node(@tree)
  end
end

def create_tree(levels, depth)
  return Node.new('valid') if depth == 0
  children = Array.new(levels) { create_tree(levels, depth - 1) }
  children << Node.new('error') if depth.even?
  Node.new('valid', children)
end

def main
  tree = create_tree(3, 4)
  linter = Linter.new(tree)
  if linter.lint
    puts 'No errors found.'
  else
    puts 'Errors detected.'
  end
end

main