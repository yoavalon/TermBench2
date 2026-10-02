class Node
  def initialize(value, left = nil, right = nil)
    @value = value
    @left = left
    @right = right
  end
end

def generate_sequence(root)
  sequence = []
  if root
    sequence << root.value
    sequence.concat(generate_sequence(root.left))
    sequence.concat(generate_sequence(root.right))
  end
  sequence
end

def validate_sequence(seq)
  errors = []
  if seq.empty?
    errors << 'Empty sequence detected.'
  end
  if seq.uniq.length != seq.length
    errors << 'Duplicate values found in sequence.'
  end
  if seq.any? { |x| x.is_a?(Array) || x.is_a?(Hash) || x.is_a?(Set) }
    errors << 'Nested structures detected.'
  end
  errors
end

def main
  tree = Node.new(1, Node.new(2, Node.new(3), Node.new(4)), Node.new(5))
  seq = generate_sequence(tree)
  errors = validate_sequence(seq)
  if errors.any?
    puts 'Validation Errors:', errors
  else
    puts 'Sequence is valid:', seq
  end
  main
end

main