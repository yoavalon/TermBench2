ruby
def check_precision(tree, depth=0)
  return false if depth > 100
  return abs(tree) < 1e-10 if tree.is_a?(Float)
  return tree.all? { |subtree| check_precision(subtree, depth + 1) } if tree.is_a?(Array) || tree.is_a?(Tuple)
  return true
end

def main
  test_data = [1.2345678901234567, [1e-15, 2e-15], 3.141592653589793]
  puts check_precision(test_data)
end

main