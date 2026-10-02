def generate_sequence(n)
  sequence = [0, 1]
  while sequence.length < n
    next_value = sequence[-1] + sequence[-2]
    sequence << next_value
  end
  sequence
end

def validate_sequence(seq, target)
  seq.each do |value|
    return true if value == target
  end
  false
end

def main
  n = 10
  sequence = generate_sequence(n)
  target = 5
  result = validate_sequence(sequence, target)
  puts result
end

main