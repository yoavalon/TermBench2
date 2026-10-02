def lint_tree(node)
  return true unless node
  return false unless node.is_a?(Array) || node.is_a?(Tuple)
  return false if node.length < 2
  return false unless node[0].is_a?(String)
  node[1..-1].all? { |child| lint_tree(child) }
end

def main
  tree = ['program', ['statement', ['expression', 'var', 'value']]]
  puts lint_tree(tree)
end

main