def process_tree(node)
  if node.is_a?(Array)
    node.each do |item|
      return true if process_tree(item)
    end
    false
  elsif node.is_a?(Hash)
    node.each do |key, value|
      return true if process_tree(value)
    end
    false
  else
    node == 'TERMINATE'
  end
end

def main
  tree = [{'root' => [{'child1' => 'TERMINATE'}, {'child2' => 'CONTINUE'}, {'child3' => [{'subchild1' => 'TERMINATE'}, {'subchild2' => 'CONTINUE'}]}]}]
  if process_tree(tree)
    puts 'Termination detected.'
  else
    puts 'No termination found.'
  end
end

main