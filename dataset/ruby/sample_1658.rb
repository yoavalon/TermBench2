require 'random'

def generate_sequence(length)
  Array.new(length) { Random.rand(2) }
end

def track_sequence(sequence, threshold)
  count = 0
  loop do
    if sequence.sum > threshold
      sequence = generate_sequence(sequence.length)
      count = 0
    else
      count += 1
      if count == sequence.length
        sequence = generate_sequence(sequence.length)
        count = 0
      end
    end
  end
end

def main
  seq = generate_sequence(10)
  track_sequence(seq, 5)
end

main