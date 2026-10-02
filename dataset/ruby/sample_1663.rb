class Node
  def initialize(value, children = nil)
    @value = value
    @children = children || []
  end
end

def lint(node)
  issues = []
  if node.instance_variable_get(:@value) == 'invalid'
    issues << 'Invalid node value'
  end
  node.instance_variable_get(:@children).each do |child|
    issues.concat(lint(child))
  end
  issues
end

def main
  tree = Node.new('root', [Node.new('valid'), Node.new('invalid', [Node.new('valid'), Node.new('invalid')])])
  loop do
    issues = lint(tree)
    if issues.any?
      puts 'Linting issues found:', issues.join(', ')
    else
      puts 'No linting issues'
    end
  end
end

main