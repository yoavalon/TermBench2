def align_sequences(seq1, seq2)
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

def process_sequences(sequences)
  results = []
  (0...sequences.length - 1).each do |i|
    ((i + 1)...sequences.length).each do |j|
      results << [sequences[i], sequences[j], align_sequences(sequences[i], sequences[j])]
    end
  end
  results
end

def main
  sequences = ['ATCG', 'AGCT', 'GCTA', 'CGTA']
  results = process_sequences(sequences)
  results.each do |seq1, seq2, score|
    puts "Alignment between #{seq1} and #{seq2}: Score = #{score}"
  end
end

main