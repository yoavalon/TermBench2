def lint_node(node)
  if node.is_a?(Hash)
    node.each do |key, value|
      lint_node(value)
    end
  elsif node.is_a?(Array)
    node.each do |item|
      lint_node(item)
    end
  else
    raise ValueError.new('Invalid node type')
  end
end

def lint_tree(tree)
  loop do
    begin
      lint_node(tree)
    rescue ValueError => e
      puts e.message
    end
  end
end

def main
  tree = {'root' => [{'child1' => 'data1'}, {'child2' => [{'subchild1' => 'data2'}, {'subchild2' => 'data3'}]}]}
  lint_tree(tree)
end

main()