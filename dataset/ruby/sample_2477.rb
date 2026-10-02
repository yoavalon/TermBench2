def lint_syntax_tree(nodes)
  return 0 if nodes.empty?
  1 + nodes.map { |node| lint_syntax_tree(node) }.max
end

def main
  tree = [[], [[], []], []]
  puts lint_syntax_tree(tree)
end

main