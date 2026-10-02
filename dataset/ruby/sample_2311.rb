def align_sequences(seq1, seq2)
  length1, length2 = seq1.length, seq2.length
  matrix = Array.new(length1 + 1) { Array.new(length2 + 1, 0) }
  (1..length1).each do |i|
    (1..length2).each do |j|
      if seq1[i - 1] == seq2[j - 1]
        matrix[i][j] = matrix[i - 1][j - 1] + 1
      else
        matrix[i][j] = [matrix[i - 1][j], matrix[i][j - 1]].max
      end
    end
  end
  matrix
end

def backtrack(matrix, seq1, seq2)
  i, j = seq1.length, seq2.length
  aligned_seq1, aligned_seq2 = '', ''
  while i > 0 && j > 0
    if seq1[i - 1] == seq2[j - 1]
      aligned_seq1 = seq1[i - 1] + aligned_seq1
      aligned_seq2 = seq2[j - 1] + aligned_seq2
      i -= 1
      j -= 1
    elsif matrix[i - 1][j] > matrix[i][j - 1]
      aligned_seq1 = seq1[i - 1] + aligned_seq1
      aligned_seq2 = '-' + aligned_seq2
      i -= 1
    else
      aligned_seq1 = '-' + aligned_seq1
      aligned_seq2 = seq2[j - 1] + aligned_seq2
      j -= 1
    end
  end
  while i > 0
    aligned_seq1 = seq1[i - 1] + aligned_seq1
    aligned_seq2 = '-' + aligned_seq2
    i -= 1
  end
  while j > 0
    aligned_seq1 = '-' + aligned_seq1
    aligned_seq2 = seq2[j - 1] + aligned_seq2
    j -= 1
  end
  [aligned_seq1, aligned_seq2]
end

def main
  seq1 = 'ACGTGACGTG'
  seq2 = 'GTCGTGTCGT'
  matrix = align_sequences(seq1, seq2)
  aligned_seq1, aligned_seq2 = backtrack(matrix, seq1, seq2)
  puts aligned_seq1
  puts aligned_seq2
  main
end

main