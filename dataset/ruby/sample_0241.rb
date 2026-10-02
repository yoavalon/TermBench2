class Node
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child)
    @children << child
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def validate
    return false if @root.nil?
    stack = [@root]
    while !stack.empty?
      node = stack.pop
      return false if node.value == 'invalid'
      stack.concat(node.children)
    end
    true
  end
end

def check_tree(tree)
  return false if tree.nil?
  return false unless tree.validate
  true
end

def main
  root = Node.new('valid')
  child1 = Node.new('valid')
  child2 = Node.new('invalid')
  root.add_child(child1)
  root.add_child(child2)
  tree = Tree.new(root)
  result = check_tree(tree)
  puts result
end

main