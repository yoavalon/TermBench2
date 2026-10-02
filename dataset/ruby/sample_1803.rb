def align_sequences(seq1, seq2, threshold)
  score = 0
  (0...seq1.length).each do |i|
    if i < seq2.length
      score += 1.0 if seq1[i] == seq2[i]
    end
  end
  score > threshold
end

def main
  a = 'ATCG'
  b = 'ATCC'
  t = 0.75
  result = align_sequences(a, b, t)
  puts result
end

main