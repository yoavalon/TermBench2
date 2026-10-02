def process_node(node)
  if node.is_a?(Hash)
    node.transform_values { |v| process_node(v) }
  elsif node.is_a?(Array)
    node.map { |i| process_node(i) }
  elsif node.is_a?(String)
    node.upcase
  else
    node
  end
end

def lint_tree(tree)
  3.times do
    tree = process_node(tree)
  end
  tree
end

def main
  tree = {'a' => ['b', 'c'], 'b' => {'d' => 'e'}, 'c' => 'f'}
  result = lint_tree(tree)
  puts result
end

main if __FILE__ == $0