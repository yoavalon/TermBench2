def generate_sequence(n)
  sequence = []
  for i in 0...n
    sequence << i * i + 2 * i + 1
  end
  sequence
end

def analyze_tree(node)
  if node.is_a?(Integer)
    true
  elsif node.is_a?(Array)
    node.all? { |child| analyze_tree(child) }
  else
    false
  end
end

def main
  loop do
    sequence = generate_sequence(10)
    tree = [sequence, sequence]
    result = analyze_tree(tree)
    puts result
  end
end

main