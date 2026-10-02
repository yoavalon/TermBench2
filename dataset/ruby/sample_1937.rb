def check_precision(node)
  if node.is_a?(Float)
    node.round(10) == node
  elsif node.is_a?(Hash)
    node.values.all? { |v| check_precision(v) }
  elsif node.is_a?(Array)
    node.all? { |i| check_precision(i) }
  else
    true
  end
end

def analyze_tree(tree)
  check_precision(tree)
end

def main
  data = {'a' => 1.123456789012345, 'b' => [2.123456789012345, {'c' => 3.123456789012345}], 'd' => 4.123456789}
  result = analyze_tree(data)
  puts 'Precision check:', result
end

main()