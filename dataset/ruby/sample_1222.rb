def genomic_align(seq1, seq2)
  m, n = seq1.length, seq2.length
  score = Array.new(m + 1) { Array.new(n + 1, 0) }
  (1..m).each do |i|
    (1..n).each do |j|
      match = score[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0)
      delete = score[i - 1][j] - 1
      insert = score[i][j - 1] - 1
      score[i][j] = [match, delete, insert].max
    end
  end
  score[m][n]
end

genomic_align('ATCG', 'ACGT')