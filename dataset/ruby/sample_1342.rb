class Node
  def initialize(value, children = [])
    @value = value
    @children = children
  end
end

def lint_tree(node)
  errors = []
  if node.is_a?(Node)
    if node.children.empty? && node.value < 0
      errors << "Negative value at node with value #{node.value}"
    end
    node.children.each do |child|
      errors.concat(lint_tree(child))
    end
  end
  errors
end

def main
  tree = Node.new(10, [Node.new(5), Node.new(-3, [Node.new(2), Node.new(-1)])])
  errors = lint_tree(tree)
  if errors.any?
    puts 'Linting Errors Found:'
    errors.each do |error|
      puts error
    end
  else
    puts 'No linting errors found.'
  end
end

main