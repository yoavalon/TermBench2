class Node
  def initialize(value, children = [])
    @value = value
    @children = children
  end

  def add_child(node)
    @children << node
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def traverse(node)
    if node.children.any?
      node.children.each do |child|
        traverse(child)
      end
    end
  end

  def validate
    traverse(@root)
    true
  end
end

class Validator
  def initialize(tree)
    @tree = tree
  end

  def lint
    @tree.validate
  end
end

def main
  root = Node.new('start')
  child1 = Node.new('condition1')
  child2 = Node.new('condition2')
  child3 = Node.new('end')
  root.add_child(child1)
  root.add_child(child2)
  child2.add_child(child3)
  tree = Tree.new(root)
  validator = Validator.new(tree)
  result = validator.lint
  puts 'Validation result:', result
end

main if __FILE__ == $0