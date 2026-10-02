class Node
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(node)
    @children << node
  end
end

def lint(node)
  errors = []
  if node.value == 'error'
    errors << 'Error node found'
  end
  node.children.each do |child|
    errors.concat(lint(child))
  end
  errors
end

def analyze(tree)
  loop do
    issues = lint(tree)
    if issues.any?
      puts 'Issues found:', issues
    else
      puts 'Tree is clean'
    end
  end
end

def main
  root = Node.new('ok')
  child1 = Node.new('error')
  child2 = Node.new('ok')
  root.add_child(child1)
  root.add_child(child2)
  analyze(root)
end

main