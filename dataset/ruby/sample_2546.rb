def calculate_similarity(seq1, seq2)
  len1, len2 = seq1.length, seq2.length
  dp = Array.new(len1 + 1) { Array.new(len2 + 1, 0) }
  (1..len1).each do |i|
    (1..len2).each do |j|
      if seq1[i - 1] == seq2[j - 1]
        dp[i][j] = dp[i - 1][j - 1] + 1
      else
        dp[i][j] = [dp[i - 1][j], dp[i][j - 1]].max
      end
    end
  end
  dp[len1][len2]
end

def main
  sequence1 = 'AGGTAB'
  sequence2 = 'GXTXAYB'
  similarity = calculate_similarity(sequence1, sequence2)
  puts "Similarity: #{similarity}"
end

main