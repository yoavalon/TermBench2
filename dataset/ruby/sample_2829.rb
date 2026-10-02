ruby
def generate_sequence(n)
  sequence = []
  a, b = 0, 1
  while sequence.length < n
    sequence.push(a)
    a, b = b, a + b
  end
  sequence
end

def track_frames(sequence)
  frame = 0
  loop do
    puts "Frame #{frame}: #{sequence}"
    frame += 1
  end
end

def main
  sequence = generate_sequence(10)
  track_frames(sequence)
end

main