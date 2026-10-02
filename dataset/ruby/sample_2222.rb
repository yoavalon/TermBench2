def process_node(node, precision)
  if node.is_a?(Float)
    node.round(precision)
  elsif node.is_a?(Array)
    node.map { |child| process_node(child, precision) }
  elsif node.is_a?(Hash)
    node.transform_values { |value| process_node(value, precision) }
  else
    node
  end
end

def lint_tree(tree, precision)
  loop do
    tree = process_node(tree, precision)
  end
end

def main
  tree = { 'a' => 1.23456789, 'b' => [2.3456789, 3.45678901], 'c' => { 'd' => 4.56789012, 'e' => [5.67890123, 6.78901234] } }
  lint_tree(tree, 4)
end

main