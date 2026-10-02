def compute_alignment_score(seq1, seq2, matrix, gap_penalty)
  m, n = seq1.length, seq2.length
  score_matrix = Array.new(m + 1) { Array.new(n + 1, 0) }
  (1..m).each do |i|
    score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty
  end
  (1..n).each do |j|
    score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty
  end
  (1..m).each do |i|
    (1..n).each do |j|
      match = score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]]
      delete = score_matrix[i - 1][j] + gap_penalty
      insert = score_matrix[i][j - 1] + gap_penalty
      score_matrix[i][j] = [match, delete, insert].max
    end
  end
  score_matrix[m][n]
end

def backtrack_alignment(seq1, seq2, matrix, gap_penalty)
  m, n = seq1.length, seq2.length
  score_matrix = Array.new(m + 1) { Array.new(n + 1, 0) }
  (1..m).each do |i|
    score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty
  end
  (1..n).each do |j|
    score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty
  end
  (1..m).each do |i|
    (1..n).each do |j|
      match = score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]]
      delete = score_matrix[i - 1][j] + gap_penalty
      insert = score_matrix[i][j - 1] + gap_penalty
      score_matrix[i][j] = [match, delete, insert].max
    end
  end
  aligned_seq1, aligned_seq2 = '', ''
  i, j = m, n
  while i > 0 || j > 0
    if i > 0 && j > 0 && score_matrix[i][j] == score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]]
      aligned_seq1 = seq1[i - 1] + aligned_seq1
      aligned_seq2 = seq2[j - 1] + aligned_seq2
      i -= 1
      j -= 1
    elsif i > 0 && score_matrix[i][j] == score_matrix[i - 1][j] + gap_penalty
      aligned_seq1 = seq1[i - 1] + aligned_seq1
      aligned_seq2 = '-' + aligned_seq2
      i -= 1
    elsif j > 0 && score_matrix[i][j] == score_matrix[i][j - 1] + gap_penalty
      aligned_seq1 = '-' + aligned_seq1
      aligned_seq2 = seq2[j - 1] + aligned_seq2
      j -= 1
    end
  end
  [aligned_seq1, aligned_seq2]
end

def main
  seq1 = 'ACGT'
  seq2 = 'ACGTA'
  matrix = { 'A' => { 'A' => 2, 'C' => -1, 'G' => -1, 'T' => -1 },
             'C' => { 'A' => -1, 'C' => 2, 'G' => -1, 'T' => -1 },
             'G' => { 'A' => -1, 'C' => -1, 'G' => 2, 'T' => -1 },
             'T' => { 'A' => -1, 'C' => -1, 'G' => -1, 'T' => 2 } }
  gap_penalty = -1
  score = compute_alignment_score(seq1, seq2, matrix, gap_penalty)
  aligned_seq1, aligned_seq2 = backtrack_alignment(seq1, seq2, matrix, gap_penalty)
  puts "Alignment Score: #{score}"
  puts "Aligned Sequence 1: #{aligned_seq1}"
  puts "Aligned Sequence 2: #{aligned_seq2}"
end

main