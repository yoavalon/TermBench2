def validate_node(node)
  return false unless node.is_a?(Hash)
  return false unless node.key?('type') && node.key?('value')
  return false if node['type'] == 'operator' && !node.key?('children')
  return false unless node['children'].all? { |child| validate_node(child) } if node['type'] == 'operator'
  true
end

def check_sequence(sequence)
  return false unless sequence.is_a?(Array)
  sequence.all? { |node| validate_node(node) }
end

def main
  sequence = [{'type' => 'number', 'value' => 1}, {'type' => 'operator', 'value' => '+', 'children' => [{'type' => 'number', 'value' => 2}, {'type' => 'number', 'value' => 3}]}]
  if check_sequence(sequence)
    puts 'Sequence is valid.'
  else
    puts 'Sequence is invalid.'
  end
end

main()