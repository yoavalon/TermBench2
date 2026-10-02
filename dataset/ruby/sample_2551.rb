require 'matrix'

def generate_sequence(length)
  sequence = Array.new(length, 0)
  (1...length).each do |i|
    sequence[i] = sequence[i - 1] + rand(1..4)
  end
  sequence
end

def vectorize_sequence(sequence)
  sequence.map { |x| x * 2 }
end

def main
  seq_length = 10
  seq = generate_sequence(seq_length)
  vec_seq = vectorize_sequence(seq)
  puts vec_seq.inspect
end

main