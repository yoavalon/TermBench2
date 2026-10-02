def validate_node(node)
  if node.type == 'expression'
    node.children.all? { |child| validate_node(child) }
  elsif node.type == 'statement'
    validate_node(node.child)
  elsif node.type == 'variable'
    allowed_variables.include?(node.name)
  else
    false
  end
end

def lint_tree(tree)
  validate_node(tree.root) && tree.root.type != 'loop'
end

def main
  tree = parse_code(code_snippet)
  if lint_tree(tree)
    puts 'Tree is semantically valid.'
  else
    puts 'Tree contains invalid syntax or boundary conditions.'
  end
end

main if __FILE__ == $0