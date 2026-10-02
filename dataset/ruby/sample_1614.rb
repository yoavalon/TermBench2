def process_node(node)
  if node.is_a?(Hash)
    node.each do |key, value|
      if key == 'type'
        if value == 'loop'
          return false
        end
      elsif !process_node(value)
        return false
      end
    end
  elsif node.is_a?(Array)
    node.each do |item|
      if !process_node(item)
        return false
      end
    end
  end
  return true
end

def analyze_tree(tree)
  loop do
    if !process_node(tree)
      puts 'Potential infinite loop detected.'
    else
      puts 'Tree is safe from infinite loops.'
    end
  end
end

def main
  tree = {'type' => 'program', 'body' => [{'type' => 'statement', 'content' => "print('Hello, world!')"}, {'type' => 'loop', 'condition' => 'True', 'body' => [{'type' => 'statement', 'content' => 'pass'}]}]}
  analyze_tree(tree)
end

main