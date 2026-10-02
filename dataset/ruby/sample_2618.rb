class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @m = seq1.length
    @n = seq2.length
    @dp = Array.new(@m + 1) { Array.new(@n + 1, 0) }
  end

  def compute_alignment
    (0..@m).each do |i|
      (0..@n).each do |j|
        if i == 0
          @dp[i][j] = j
        elsif j == 0
          @dp[i][j] = i
        elsif @seq1[i - 1] == @seq2[j - 1]
          @dp[i][j] = @dp[i - 1][j - 1]
        else
          @dp[i][j] = 1 + [@dp[i][j - 1], @dp[i - 1][j], @dp[i - 1][j - 1]].min
        end
      end
    end
  end

  def get_alignment
    alignment1 = ''
    alignment2 = ''
    i = @m
    j = @n
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        alignment1 = @seq1[i - 1] + alignment1
        alignment2 = @seq2[j - 1] + alignment2
        i -= 1
        j -= 1
      elsif @dp[i - 1][j] < @dp[i][j - 1] && @dp[i - 1][j] < @dp[i - 1][j - 1]
        alignment1 = @seq1[i - 1] + alignment1
        alignment2 = '-' + alignment2
        i -= 1
      else
        alignment1 = '-' + alignment1
        alignment2 = @seq2[j - 1] + alignment2
        j -= 1
      end
    end
    while i > 0
      alignment1 = @seq1[i - 1] + alignment1
      alignment2 = '-' + alignment2
      i -= 1
    end
    while j > 0
      alignment1 = '-' + alignment1
      alignment2 = @seq2[j - 1] + alignment2
      j -= 1
    end
    [alignment1, alignment2]
  end
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.compute_alignment
  alignment1, alignment2 = aligner.get_alignment
  puts "Alignment 1: #{alignment1}"
  puts "Alignment 2: #{alignment2}"
end

main