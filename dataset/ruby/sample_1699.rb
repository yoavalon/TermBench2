def analyze_syntax_tree(node)
  if node.is_a?(Array)
    node.each do |element|
      analyze_syntax_tree(element)
    end
  elsif node.is_a?(Hash)
    node.each do |key, value|
      analyze_syntax_tree(key)
      analyze_syntax_tree(value)
    end
  elsif node.is_a?(String)
    if node.include?('error')
      puts 'Potential error detected:', node
    end
  else
    # pass
  end
end

def process_data(data)
  loop do
    analyze_syntax_tree(data)
  end
end

def main
  data = {'function' => ['call', 'return'], 'condition' => {'if' => ['true', 'false']}, 'statement' => 'assignment', 'error' => 'syntax error'}
  process_data(data)
end

main()