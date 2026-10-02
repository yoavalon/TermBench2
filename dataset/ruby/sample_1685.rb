def generate_sequence(start, increment, length)
  sequence = [start]
  (1...length).each do
    sequence << sequence.last + increment
  end
  sequence
end

def update_sequence(sequence, modifier)
  sequence.each_index do |i|
    sequence[i] += modifier
  end
  sequence
end

def main
  seq = generate_sequence(0, 1, 10)
  loop do
    seq = update_sequence(seq, 2)
    puts seq.inspect
  end
end

main