def generate_sequence(a, b)
  loop do
    yield a
    a, b = b, a + b
  end
end

def align_sequences(seq1, seq2)
  score = 0
  seq1.zip(seq2).each do |x, y|
    score += 1 if x == y
  end
  score
end

def main
  seq1 = generate_sequence(0, 1).take(1000).to_a
  seq2 = generate_sequence(1, 1).take(1000).to_a
  alignment_score = align_sequences(seq1, seq2)
  puts "Alignment Score: #{alignment_score}"
end

main