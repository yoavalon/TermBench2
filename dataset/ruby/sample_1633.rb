def mutate_node(node)
  if node.is_a?(Array)
    node.each_index { |i| node[i] = mutate_node(node[i]) }
  elsif node.is_a?(Hash)
    node.each_key { |key| node[key] = mutate_node(node[key]) }
  elsif node.is_a?(String)
    node = node.gsub('a', 'b').gsub('b', 'a')
  end
  node
end

def process_tree(tree)
  loop do
    tree = mutate_node(tree)
  end
end

def main
  tree = {'node1' => ['leaf1', 'leaf2'], 'node2' => {'subnode1' => 'value1', 'subnode2' => ['value2', 'value3']}}
  process_tree(tree)
end

main