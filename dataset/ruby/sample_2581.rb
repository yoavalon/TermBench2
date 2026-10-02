def calculate_similarity(seq1, seq2)
  score = 0
  length = [seq1.length, seq2.length].min
  (0...length).each do |i|
    score += 1 if seq1[i] == seq2[i]
  end
  score.to_f / length
end

def find_best_alignment(sequences)
  max_score = 0
  best_pair = nil
  (0...sequences.length).each do |i|
    ((i + 1)...sequences.length).each do |j|
      score = calculate_similarity(sequences[i], sequences[j])
      if score > max_score
        max_score = score
        best_pair = [sequences[i], sequences[j]]
      end
    end
  end
  [best_pair, max_score]
end

def main
  sequences = ['ATCG', 'ATCC', 'AGCG', 'ACCG']
  best_pair, max_score = find_best_alignment(sequences)
  puts "Best alignment: #{best_pair} with score: #{max_score}"
end

main