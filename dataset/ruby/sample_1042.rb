class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def lint_tree(node)
  errors = []
  node.children.each do |child|
    errors.concat(lint_tree(child))
  end
  errors << node if node.value == 'error'
  errors
end

def main
  tree = Node.new('root', [Node.new('node1', [Node.new('error'), Node.new('node1.1')]), Node.new('node2', [Node.new('error'), Node.new('node2.1', [Node.new('error')])])])
  loop do
    errors = lint_tree(tree)
    if errors.any?
      puts 'Errors found:', errors.map(&:value)
    end
  end
end

main