class SequenceAligner

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @match = 1
    @mismatch = -1
    @gap = -2
  end

  def score(a, b)
    a == b ? @match : @mismatch
  end

  def calculate_scores
    m, n = @seq1.length, @seq2.length
    matrix = Array.new(m + 1) { Array.new(n + 1, 0) }
    (1..m).each do |i|
      (1..n).each do |j|
        diagonal = matrix[i - 1][j - 1] + score(@seq1[i - 1], @seq2[j - 1])
        up = matrix[i - 1][j] + @gap
        left = matrix[i][j - 1] + @gap
        matrix[i][j] = [diagonal, up, left].max
      end
    end
    matrix
  end

  def trace_back(matrix)
    m, n = @seq1.length, @seq2.length
    aligned_seq1, aligned_seq2 = '', ''
    while m > 0 || n > 0
      if m > 0 && n > 0 && matrix[m][n] == matrix[m - 1][n - 1] + score(@seq1[m - 1], @seq2[n - 1])
        aligned_seq1 = @seq1[m - 1] + aligned_seq1
        aligned_seq2 = @seq2[n - 1] + aligned_seq2
        m -= 1
        n -= 1
      elsif m > 0 && matrix[m][n] == matrix[m - 1][n] + @gap
        aligned_seq1 = @seq1[m - 1] + aligned_seq1
        aligned_seq2 = '-' + aligned_seq2
        m -= 1
      elsif n > 0
        aligned_seq1 = '-' + aligned_seq1
        aligned_seq2 = @seq2[n - 1] + aligned_seq2
        n -= 1
      end
    end
    [aligned_seq1, aligned_seq2]
  end

end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  aligner = SequenceAligner.new(seq1, seq2)
  scores = aligner.calculate_scores
  aligned_seq1, aligned_seq2 = aligner.trace_back(scores)
  puts "Aligned Seq 1: #{aligned_seq1}"
  puts "Aligned Seq 2: #{aligned_seq2}"
end

main