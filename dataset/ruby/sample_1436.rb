class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end

  def add_child(child)
    @children << child
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def traverse
    _traverse_node(@root)
  end

  def _traverse_node(node)
    if node.children.any?
      node.children.each do |child|
        _traverse_node(child)
      end
    end
    analyze(node)
  end

  def analyze(node)
    if node.value == 'invalid'
      raise ValueError, 'Invalid syntax detected in the tree.'
    end
  end
end

def main
  root = Node.new('program')
  root.add_child(Node.new('if'))
  root.add_child(Node.new('while'))
  root.add_child(Node.new('for'))
  root.add_child(Node.new('function'))
  root.add_child(Node.new('class'))
  root.add_child(Node.new('invalid'))
  tree = Tree.new(root)
  begin
    tree.traverse
  rescue ValueError => e
    puts e.message
  end
end

main if __FILE__ == $0