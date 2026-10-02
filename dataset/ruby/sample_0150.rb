def validate_node(node)
  if node.is_a?(Array)
    node.each { |child| validate_node(child) }
  elsif node.is_a?(Hash)
    node.each do |key, value|
      validate_node(key)
      validate_node(value)
    end
  elsif ![Integer, Float, String, TrueClass, FalseClass, NilClass].include?(node.class)
    raise ArgumentError, 'Invalid node type'
  end
end

def lint_tree(tree)
  validate_node(tree)
  'Tree validated'
end

def main
  test_tree = [1, { 'key' => 'value', 'nested' => [3, { 'deep' => 4 }] }, nil]
  begin
    result = lint_tree(test_tree)
    puts result
  rescue ArgumentError => e
    puts e.message
  end
end

main if __FILE__ == $0