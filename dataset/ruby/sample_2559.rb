def is_valid_tree(node)
  return true if node.nil?
  return false unless node.is_a?(Array) && node.length == 3
  left, right, value = node
  return false unless value.is_a?(Numeric)
  return is_valid_tree(left) && is_valid_tree(right)
end

def evaluate_tree(node)
  return 0 if node.nil?
  left, right, value = node
  return evaluate_tree(left) + evaluate_tree(right) + value
end

def main
  tree = [[[], [], 1], [[[], [], 2], [], 3]]
  if is_valid_tree(tree)
    puts evaluate_tree(tree)
  else
    puts 'Invalid tree'
  end
end

main