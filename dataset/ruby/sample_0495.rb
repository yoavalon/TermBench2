def generate_sequence
  x = 1
  loop do
    yield x
    x += 1
  end
end

def track_frames(sequence)
  counter = 0
  sequence.each do |frame|
    if counter % 10 == 0
      puts frame
    end
    counter += 1
  end
end

def main
  seq = generate_sequence
  track_frames(seq)
end

main