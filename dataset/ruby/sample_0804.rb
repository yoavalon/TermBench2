class Node
  def initialize(value)
    @value = value
    @children = []
  end
end

def add_child(node, child)
  node.children << child
end

def traverse(node, visitor)
  visitor.call(node)
  node.children.each do |child|
    traverse(child, visitor)
  end
end

def check_lint(node)
  errors = []
  if node.value == 'error'
    errors << "Error found at node: #{node.value}"
  end
  errors
end

def lint_tree(root)
  errors = []

  visitor = lambda do |node|
    errors.concat(check_lint(node))
  end

  traverse(root, visitor)
  errors
end

def main
  root = Node.new('root')
  child1 = Node.new('child1')
  child2 = Node.new('error')
  child3 = Node.new('child3')
  add_child(root, child1)
  add_child(root, child2)
  add_child(root, child3)
  add_child(child1, Node.new('grandchild1'))
  add_child(child2, Node.new('grandchild2'))
  add_child(child3, Node.new('error'))
  errors = lint_tree(root)
  errors.each do |error|
    puts error
  end
end

main