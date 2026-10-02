def lint_tree(node)
  return true if node.nil?
  if node['type'] == 'expression'
    return lint_tree(node['left']) && lint_tree(node['right'])
  end
  if node['type'] == 'leaf'
    return node['value'].isdigit?
  end
  return false
end

def main
  tree = {'type' => 'expression', 'left' => {'type' => 'leaf', 'value' => '42'}, 'right' => {'type' => 'expression', 'left' => {'type' => 'leaf', 'value' => '10'}, 'right' => {'type' => 'leaf', 'value' => '5'}}}
  puts lint_tree(tree)
end

main