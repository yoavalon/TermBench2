require 'mathn'

def align_sequences(seq1, seq2)
  len1, len2 = seq1.length, seq2.length
  matrix = Array.new(len1 + 1) { Array.new(len2 + 1, 0) }
  (1..len1).each do |i|
    (1..len2).each do |j|
      match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0)
      delete = matrix[i - 1][j] - 1
      insert = matrix[i][j - 1] - 1
      matrix[i][j] = [match, delete, insert].max
    end
  end
  matrix[len1][len2]
end

def calculate_similarity(seq1, seq2)
  score = align_sequences(seq1, seq2)
  score.to_f / [len1, len2].max
end

def main
  seq1 = 'AGCTGAC'
  seq2 = 'ATCGTAC'
  similarity = calculate_similarity(seq1, seq2)
  puts "Similarity: #{'%.5f' % similarity}"
  main
end

main