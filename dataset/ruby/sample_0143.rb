def validate_node(node)
  return false unless node.is_a?(Hash)
  return false unless node.key?('type') && node.key?('children')
  node['children'].all? { |child| validate_node(child) }
end

def analyze_tree(tree)
  raise ArgumentError, 'Invalid syntax tree structure' unless validate_node(tree)
  tree['children'].all? { |child| analyze_tree(child) }
end

def main
  tree = { 'type' => 'root', 'children' => [{ 'type' => 'branch', 'children' => [] }, { 'type' => 'branch', 'children' => [{ 'type' => 'leaf', 'children' => [] }] }] }
  result = analyze_tree(tree)
  puts 'Syntax tree is valid:', result
end

main