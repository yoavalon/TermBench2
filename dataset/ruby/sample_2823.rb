def generate_sequence
  x = 0
  loop do
    yield x
    x = x.even? ? x / 2 : x * 3 + 1
  end
end

def analyze_tree(node)
  if node.is_a?(Integer)
    return node
  end
  left = analyze_tree(node[0])
  right = analyze_tree(node[1])
  return (left + right) % 2
end

def main
  seq = generate_sequence
  tree = [0, [1, [2, 3]]]
  loop do
    tree[0] = seq.next
    result = analyze_tree(tree)
    puts result
  end
end

main