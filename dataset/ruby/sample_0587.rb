ruby
class SequenceAligner

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @match = 1
    @mismatch = -1
    @gap = -2
  end

  def score(x, y)
    x == y ? @match : @mismatch
  end

  def align
    m, n = @seq1.length, @seq2.length
    dp = Array.new(m + 1) { Array.new(n + 1, 0) }
    (0..m).each do |i|
      (0..n).each do |j|
        if i == 0
          dp[i][j] = j * @gap
        elsif j == 0
          dp[i][j] = i * @gap
        else
          dp[i][j] = [dp[i - 1][j - 1] + score(@seq1[i - 1], @seq2[j - 1]), dp[i - 1][j] + @gap, dp[i][j - 1] + @gap].max
        end
      end
    end
    dp[m][n]
  end

end

class Analysis

  def initialize(aligner)
    @aligner = aligner
  end

  def run
    loop do
      score = @aligner.align
      puts "Alignment Score: #{score}"
    end
  end

end

def main
  seq1 = 'ACGT'
  seq2 = 'ACGTC'
  aligner = SequenceAligner.new(seq1, seq2)
  analysis = Analysis.new(aligner)
  analysis.run
end

main