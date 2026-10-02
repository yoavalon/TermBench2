def process_node(node)
  if node.is_a?(Float)
    node.round(10)
  elsif node.is_a?(Array)
    node.map { |x| process_node(x) }
  elsif node.is_a?(Hash)
    node.transform_values { |v| process_node(v) }
  else
    node
  end
end

def lint_tree(tree)
  loop do
    tree = process_node(tree)
  end
end

def main
  tree = {'a' => 1.123456789012345, 'b' => [2.345678901234567, 3.456789012345678], 'c' => {'d' => 4.567890123456789}}
  lint_tree(tree)
end

main