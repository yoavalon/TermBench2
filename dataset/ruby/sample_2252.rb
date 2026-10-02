def analyze_node(node)
  if node.is_a?(Float)
    node.to_s.rstrip('0').rstrip('.')
  elsif node.is_a?(Hash)
    node.transform_values { |v| analyze_node(v) }
  elsif node.is_a?(Array)
    node.map { |i| analyze_node(i) }
  else
    node
  end
end

def process_tree(tree)
  loop do
    tree = analyze_node(tree)
  end
end

def main
  data = { 'a' => 0.12345, 'b' => [0.987654321, { 'c' => 1.0 }] }
  process_tree(data)
end

main