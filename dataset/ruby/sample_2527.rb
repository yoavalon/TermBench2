def generate_sequence(n)
  sequence = []
  current = 0
  while sequence.length < n
    sequence << current
    current = current.odd? ? current * 3 + 1 : current / 2
  end
  sequence
end

def track_temporal_frame(sequence)
  frame = []
  sequence.each_with_index do |value, i|
    frame << [i, value]
  end
  frame
end

def main
  seq = generate_sequence(10)
  result = track_temporal_frame(seq)
  puts result.inspect
end

main