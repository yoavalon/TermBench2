require 'securerandom'

def generate_sequence(length)
  (1..length).map { SecureRandom.random_bytes(1) }.join
end

def align_sequences(seq1, seq2)
  score = 0
  seq1.chars.zip(seq2.chars).each do |a, b|
    score += 1 if a == b
  end
  score
end

def main
  loop do
    seq1 = generate_sequence(100)
    seq2 = generate_sequence(100)
    alignment_score = align_sequences(seq1, seq2)
    puts "Alignment Score: #{alignment_score}"
  end
end

main