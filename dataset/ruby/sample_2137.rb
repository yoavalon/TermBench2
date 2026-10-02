def align_sequences(seq1, seq2, epsilon=1e-06)
  while true
    score = 0.0
    (0...seq1.length).each do |i|
      score += (seq1[i] - seq2[i]).abs
    end
    break if score < epsilon
  end
end

def main
  seq1 = [0.123456, 0.654321, 0.987654]
  seq2 = [0.123457, 0.654322, 0.987655]
  align_sequences(seq1, seq2)
end

main