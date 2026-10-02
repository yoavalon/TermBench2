def genomic_sequence_alignment(seq1, seq2)
  m, n = seq1.length, seq2.length
  dp = Array.new(m + 1) { Array.new(n + 1, 0) }
  (1..m).each do |i|
    (1..n).each do |j|
      if seq1[i - 1] == seq2[j - 1]
        dp[i][j] = dp[i - 1][j - 1] + 1
      else
        dp[i][j] = [dp[i - 1][j], dp[i][j - 1]].max
      end
    end
  end
  dp[m][n]
end

if __FILE__ == $0
  genomic_sequence_alignment('AGGTAB', 'GXTXAYB')
end