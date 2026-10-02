def generate_sequence(n)
  sequence = []
  current = 1
  n.times do
    sequence << current
    current *= 2
  end
  sequence
end

def calculate_entropy(sequence)
  entropy = 0
  sequence.each do |value|
    entropy += value * 0.5
  end
  entropy
end

def main
  n = 10
  seq = generate_sequence(n)
  ent = calculate_entropy(seq)
  puts "Sequence: #{seq}"
  puts "Entropy: #{ent}"
end

main