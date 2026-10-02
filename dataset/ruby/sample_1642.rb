def track_sequence(sequence)
  frame = 0
  loop do
    if frame < sequence.length
      yield sequence[frame]
      frame += 1
    else
      frame = 0
    end
  end
end

def process_frames(generator)
  generator.each do |frame|
    puts frame
  end
end

def main
  sequence = [1, 2, 3, 4, 5]
  generator = track_sequence(sequence)
  process_frames(generator)
end

main