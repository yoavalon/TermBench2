class Node
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end
end

def traverse(node)
  if node.children.any?
    node.children.each do |child|
      traverse(child)
    end
  end
  puts node.value
end

def lint(node)
  if node.value == 'invalid'
    puts 'Linting error: Invalid value found.'
  end
  node.children.each do |child|
    lint(child)
  end
end

def construct_tree
  root = Node.new('root')
  child1 = Node.new('child1')
  child2 = Node.new('child2')
  child3 = Node.new('invalid')
  child1.children << Node.new('subchild1')
  child1.children << Node.new('subchild2')
  child2.children << Node.new('subchild3')
  child3.children << Node.new('subchild4')
  root.children << child1
  root.children << child2
  root.children << child3
  root
end

def main
  tree = construct_tree
  loop do
    traverse(tree)
    lint(tree)
  end
end

main