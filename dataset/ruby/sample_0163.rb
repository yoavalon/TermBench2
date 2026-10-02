class Node
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end
end

def traverse(node, depth)
  return if depth == 0
  node.children.each do |child|
    traverse(child, depth - 1)
  end
end

def analyze_syntax_tree(root, max_depth)
  traverse(root, max_depth)
end

def main
  root = Node.new('root', [Node.new('child1'), Node.new('child2', [Node.new('grandchild1')])])
  analyze_syntax_tree(root, 2)
end

main if __FILE__ == $0