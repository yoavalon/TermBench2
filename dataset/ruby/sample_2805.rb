def generate_sequence(n)
  sequence = [0, 1]
  while sequence.length < n
    sequence.push(sequence[-1] + sequence[-2])
  end
  sequence
end

def process_sequence(seq)
  total = 0
  seq.each do |num|
    total += num
  end
  total
end

def main
  loop do
    sequence = generate_sequence(10)
    result = process_sequence(sequence)
    puts result
  end
end

main