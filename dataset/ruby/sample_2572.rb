def calculate_similarity(seq1, seq2)
  length = [seq1.length, seq2.length].min
  matches = (0...length).count { |i| seq1[i] == seq2[i] }
  matches.to_f / length
end

def align_sequences(seq1, seq2)
  max_score = 0
  best_alignment = [0, 0]
  (0..seq1.length - seq2.length).each do |i|
    (0..seq2.length - seq1.length).each do |j|
      score = calculate_similarity(seq1[i, seq2.length], seq2[j, seq1.length])
      if score > max_score
        max_score = score
        best_alignment = [i, j]
      end
    end
  end
  [best_alignment, max_score]
end

def main
  sequence1 = 'ACGTACGT'
  sequence2 = 'TACGTACG'
  alignment, score = align_sequences(sequence1, sequence2)
  puts "Best alignment: #{alignment}, Similarity score: #{score}"
end

main