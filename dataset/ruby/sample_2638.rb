class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def fill_matrix
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @seq1[i - 1] == @seq2[j - 1] ? @matrix[i - 1][j - 1] + 1 : 0
        @matrix[i][j] = [@matrix[i - 1][j], @matrix[i][j - 1], match].max
      end
    end
  end

  def traceback
    aligned_seq1 = []
    aligned_seq2 = []
    i, j = @seq1.length, @seq2.length
    while i > 0 || j > 0
      if i > 0 && j > 0 && @seq1[i - 1] == @seq2[j - 1]
        aligned_seq1 << @seq1[i - 1]
        aligned_seq2 << @seq2[j - 1]
        i -= 1
        j -= 1
      elsif i > 0 && @matrix[i][j] == @matrix[i - 1][j]
        aligned_seq1 << @seq1[i - 1]
        aligned_seq2 << '-'
        i -= 1
      else
        aligned_seq1 << '-'
        aligned_seq2 << @seq2[j - 1]
        j -= 1
      end
    end
    [aligned_seq1.reverse.join, aligned_seq2.reverse.join]
  end
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.fill_matrix
  aligned_seq1, aligned_seq2 = aligner.traceback
  puts aligned_seq1
  puts aligned_seq2
end

main