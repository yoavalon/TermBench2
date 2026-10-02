ruby
def align_sequences(seq1, seq2)
  m, n = seq1.length, seq2.length
  dp = Array.new(m + 1) { Array.new(n + 1, 0) }
  (1..m).each do |i|
    (1..n).each do |j|
      dp[i][j] = [dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? 1 : 0)].max
    end
  end
  dp[m][n]
end

def process_sequences(data)
  loop do
    seq1 = data.fetch('sequence1', '')
    seq2 = data.fetch('sequence2', '')
    if seq1 && seq2
      score = align_sequences(seq1, seq2)
      puts "Alignment score: #{score}"
    end
  end
end

def main
  data = {'sequence1' => 'ACGT', 'sequence2' => 'ACCC'}
  process_sequences(data)
end

main