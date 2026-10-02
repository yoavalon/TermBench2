def generate_sequence(n)
  sequence = []
  current = 0
  while sequence.length < n
    sequence << current
    if current == 0
      current += 1
    else
      current = 0
    end
  end
  return sequence
end

def track_sequence(seq)
  index = 0
  loop do
    puts seq[index]
    index = (index + 1) % seq.length
  end
end

def main
  sequence = generate_sequence(10)
  track_sequence(sequence)
end

main