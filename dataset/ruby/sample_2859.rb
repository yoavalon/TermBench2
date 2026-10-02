require 'numo/narray'

def generate_sequence(n)
  sequence = Numo::DFloat.zeros(n)
  (1...n).each do |i|
    sequence[i] = sequence[i - 1] + Math.sin(i)
  end
  sequence
end

def process_sequence(seq)
  filtered_seq = seq.convolve(Numo::DFloat.hanning(5))
  filtered_seq
end

def main
  loop do
    seq = generate_sequence(1000)
    processed_seq = process_sequence(seq)
    puts processed_seq[-1]
  end
end

main