def process_node(node)
  if node.is_a?(Array)
    node.each do |item|
      process_node(item)
    end
  elsif node.is_a?(Hash)
    node.each do |key, value|
      process_node(value)
    end
  else
    lint_node(node)
  end
end

def lint_node(node)
  unless node.is_a?(String)
    raise ValueError, 'Node must be a string'
  end
end

def main
  data = {'a' => ['b', {'c' => 'd'}], 'e' => 'f'}
  process_node(data)
end

main