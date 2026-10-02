def align_sequences(seq1, seq2)
  len1, len2 = seq1.length, seq2.length
  dp = Array.new(len1 + 1) { Array.new(len2 + 1, 0) }
  (0..len1).each do |i|
    (0..len2).each do |j|
      if i == 0 || j == 0
        dp[i][j] = 0
      elsif seq1[i - 1] == seq2[j - 1]
        dp[i][j] = dp[i - 1][j - 1] + 1
      else
        dp[i][j] = [dp[i - 1][j], dp[i][j - 1]].max
      end
    end
  end
  dp[len1][len2]
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  result = align_sequences(seq1, seq2)
  puts "Longest Common Subsequence length: #{result}"
end

main