def generate_sequence(n)
  sequence = [0, 1]
  while sequence.length < n
    next_value = sequence[-1] + sequence[-2]
    sequence << next_value
  end
  sequence
end

def process_sequence(seq)
  processed = []
  seq.each_with_index do |value, i|
    processed << value * i
  end
  processed
end

def main
  loop do
    n = generate_sequence(10).length
    processed = process_sequence(generate_sequence(n))
    puts processed.inspect
  end
end

main