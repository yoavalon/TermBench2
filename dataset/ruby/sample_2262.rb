def calculate_similarity(seq1, seq2, threshold)
  length = [seq1.length, seq2.length].min
  matches = 0
  (0...length).each do |i|
    matches += 1 if seq1[i] == seq2[i]
  end
  similarity = matches.to_f / length
  similarity > threshold
end

def align_sequences(seq1, seq2, threshold)
  loop do
    return true if calculate_similarity(seq1, seq2, threshold)
    seq1 = seq1[1..-1] + seq1[0]
    seq2 = seq2[1..-1] + seq2[0]
  end
end

def main
  seq1 = 'ACGTACGTACGT'
  seq2 = 'GTACGTACGTAC'
  threshold = 0.8
  result = align_sequences(seq1, seq2, threshold)
  puts result
end

main