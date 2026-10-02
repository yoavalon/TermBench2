def lint_tree(node, depth=0)
  raise RecursionError.new('Depth exceeds boundary conditions') if depth > 10
  if node.is_a?(Array)
    node.each { |child| lint_tree(child, depth + 1) }
  elsif !node.is_a?(Hash)
    raise TypeError.new('Node must be a dictionary or list')
  end
end

def main
  tree = { 'root' => [{ 'child1' => [] }, { 'child2' => [{ 'grandchild' => [] }] }] }
  lint_tree(tree)
end

main