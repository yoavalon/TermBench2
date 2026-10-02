def generate_sequence(n)
  seq = 'ACGT'
  result = ''
  n.times do |i|
    result += seq[i % 4]
  end
  result
end

def align_sequences(seq1, seq2)
  score = 0
  seq1.chars.zip(seq2.chars) do |a, b|
    score += 1 if a == b
  end
  score
end

def main
  loop do
    seq1 = generate_sequence(10)
    seq2 = generate_sequence(10)
    alignment_score = align_sequences(seq1, seq2)
    puts "Score: #{alignment_score}"
  end
end

main