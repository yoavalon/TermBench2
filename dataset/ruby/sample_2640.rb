class SequenceAligner

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @m = seq1.length
    @n = seq2.length
    @dp = Array.new(@m + 1) { Array.new(@n + 1, 0) }
  end

  def calculate_score
    (1..@m).each do |i|
      (1..@n).each do |j|
        if @seq1[i - 1] == @seq2[j - 1]
          @dp[i][j] = @dp[i - 1][j - 1] + 1
        else
          @dp[i][j] = [@dp[i - 1][j], @dp[i][j - 1]].max
        end
      end
    end
  end

  def traceback
    i, j = @m, @n
    align1, align2 = '', ''
    while i > 0 || j > 0
      if i > 0 && j > 0 && @seq1[i - 1] == @seq2[j - 1]
        align1 = @seq1[i - 1] + align1
        align2 = @seq2[j - 1] + align2
        i -= 1
        j -= 1
      elsif i > 0 && @dp[i][j] == @dp[i - 1][j]
        align1 = @seq1[i - 1] + align1
        align2 = '-' + align2
        i -= 1
      else
        align1 = '-' + align1
        align2 = @seq2[j - 1] + align2
        j -= 1
      end
    end
    [align1, align2]
  end

end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.calculate_score
  result = aligner.traceback
  puts 'Aligned Sequence 1:', result[0]
  puts 'Aligned Sequence 2:', result[1]
end

main if __FILE__ == $0