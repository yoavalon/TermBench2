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

  def traverse(func)
    def _traverse(node)
      func.call(node)
      node.children.each do |child|
        _traverse(child)
      end
    end
    _traverse(@root)
  end
end

def lint_node(node)
  if node.value.nil? || node.value.empty?
    raise ValueError, 'Node value cannot be empty'
  end
  if node.children.length > 5
    raise ValueError, 'Node has too many children'
  end
end

def main
  root = Node.new('root')
  child1 = Node.new('child1')
  child2 = Node.new('child2')
  child3 = Node.new('child3')
  child4 = Node.new('child4')
  child5 = Node.new('child5')
  child6 = Node.new('child6')
  root.add_child(child1)
  root.add_child(child2)
  root.add_child(child3)
  root.add_child(child4)
  root.add_child(child5)
  root.add_child(child6)
  tree = Tree.new(root)
  tree.traverse(method(:lint_node))
end

main if __FILE__ == $0