def align_sequences(seq1, seq2)
  m, n = seq1.length, seq2.length
  dp = Array.new(m + 1) { Array.new(n + 1, 0) }
  (0..m).each { |i| dp[i][0] = i }
  (0..n).each { |j| dp[0][j] = j }
  (1..m).each do |i|
    (1..n).each do |j|
      cost = seq1[i - 1] == seq2[j - 1] ? 0 : 1
      dp[i][j] = [dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost].min
    end
  end
  dp[m][n]
end

def process_sequences(sequences)
  total_cost = 0
  sequences.each do |seq1, seq2|
    total_cost += align_sequences(seq1, seq2)
  end
  total_cost
end

def main
  sequences = [['AGCT', 'ACGT'], ['GATTACA', 'GCTACGA']]
  result = process_sequences(sequences)
  puts result
end

main