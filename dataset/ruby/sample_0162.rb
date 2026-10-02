def validate_node(node)
  return true if node.nil?
  return false unless node.is_a?(Array) && node.length == 3
  return false unless node[0].is_a?(String)
  return false unless validate_node(node[1]) && validate_node(node[2])
  true
end

def analyze_tree(tree)
  raise ArgumentError, 'Invalid syntax tree structure' unless validate_node(tree)
  stack = [tree]
  while !stack.empty?
    node = stack.pop
    stack.concat(node[1..2].compact)
  end
  true
end

def main
  tree = ['root', ['child1', nil, nil], ['child2', ['grandchild1', nil, nil], nil]]
  analyze_tree(tree)
end

main