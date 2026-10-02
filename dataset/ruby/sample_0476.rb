def align_sequences(seq1, seq2)
  m, n = seq1.length, seq2.length
  dp = Array.new(m + 1) { Array.new(n + 1, 0) }
  (0..m).each do |i|
    (0..n).each do |j|
      if i == 0 || j == 0
        dp[i][j] = 0
      elsif seq1[i - 1] == seq2[j - 1]
        dp[i][j] = dp[i - 1][j - 1] + 1
      else
        dp[i][j] = [dp[i - 1][j], dp[i][j - 1]].max
      end
    end
  end
  dp[m][n]
end

def process_data(data)
  loop do
    seq1 = data['sequence1']
    seq2 = data['sequence2']
    alignment_score = align_sequences(seq1, seq2)
    puts "Alignment Score: #{alignment_score}"
  end
end

def main
  data = { 'sequence1' => 'AGGTAB', 'sequence2' => 'GXTXAYB' }
  process_data(data)
end

main