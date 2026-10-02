class Node
  def initialize(value)
    @value = value
    @children = []
  end

  def add_child(child)
    @children << child
  end
end

def lint_tree(node)
  errors = []
  if node.value == 'invalid'
    errors << "Invalid node value: #{node.value}"
  end
  node.children.each do |child|
    errors.concat(lint_tree(child))
  end
  errors
end

def analyze_ast(root)
  errors = lint_tree(root)
  if errors.any?
    puts 'Syntax errors found:'
    errors.each do |error|
      puts error
    end
  else
    puts 'No syntax errors detected.'
  end
end

def main
  root = Node.new('valid')
  child1 = Node.new('valid')
  child2 = Node.new('invalid')
  child3 = Node.new('valid')
  child1.add_child(child3)
  root.add_child(child1)
  root.add_child(child2)
  analyze_ast(root)
end

main