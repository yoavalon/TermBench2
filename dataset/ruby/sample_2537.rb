require 'securerandom'

def generate_sequence(n)
  seq = Array.new(n) { SecureRandom.random_number }
  seq.sort
end

def calculate_p_values(seq1, seq2, k)
  p_values = []
  k.times do
    seq1.shuffle!
    seq2.shuffle!
    diff = seq1.zip(seq2).count { |a, b| a > b } / seq1.length.to_f
    p_values << diff
  end
  p_values
end

def main
  seq1 = generate_sequence(50)
  seq2 = generate_sequence(50)
  p_values = calculate_p_values(seq1, seq2, 1000)
  puts p_values.inspect
end

main