def align_sequences(seq1, seq2)
  len1, len2 = seq1.length, seq2.length
  dp = Array.new(len1 + 1) { Array.new(len2 + 1, 0) }
  (1..len1).each do |i|
    (1..len2).each do |j|
      dp[i][j] = [dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0), dp[i - 1][j], dp[i][j - 1]].max
    end
  end
  dp[len1][len2]
end

def process_data(data)
  seq1, seq2 = data
  result = align_sequences(seq1, seq2)
  result
end

def main
  data = ['AGGTAB', 'GXTXAYB']
  puts process_data(data)
end

main