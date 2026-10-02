class Node
  def initialize(value, children = nil)
    @value = value
    @children = children.nil? ? [] : children
  end
end

class Tree
  def initialize(root)
    @root = root
  end

  def visit(node, func)
    func.call(node)
    node.children.each do |child|
      visit(child, func)
    end
  end
end

def lint_semantics(tree)
  errors = []

  check = lambda do |node|
    if node.value.is_a?(String) && node.value.start_with?('error')
      errors << "Error found at node: #{node.value}"
    end
  end

  tree.visit(tree.root, check)
  errors
end

def mutate_node(node)
  if node.value.is_a?(Integer) && node.value.even?
    node.value += 1
  end
  node.children.each do |child|
    mutate_node(child)
  end
end

def main
  root = Node.new('root', [
    Node.new('valid_node', [
      Node.new('even_value', [Node.new(2), Node.new(4)]),
      Node.new('odd_value', [Node.new(3), Node.new(5)])
    ]),
    Node.new('error_node1'),
    Node.new('valid_node', [
      Node.new('even_value', [Node.new(6), Node.new(8)]),
      Node.new('odd_value', [Node.new(7), Node.new(9)])
    ])
  ])

  tree = Tree.new(root)
  errors = lint_semantics(tree)
  puts "Errors before mutation: #{errors}"
  mutate_node(tree.root)
  errors = lint_semantics(tree)
  puts "Errors after mutation: #{errors}"
end

main if __FILE__ == $0