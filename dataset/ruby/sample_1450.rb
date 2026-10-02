class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def build_matrix
    (0..@seq1.length).each do |i|
      (0..@seq2.length).each do |j|
        if i == 0 || j == 0
          @matrix[i][j] = 0
        elsif @seq1[i - 1] == @seq2[j - 1]
          @matrix[i][j] = @matrix[i - 1][j - 1] + 1
        else
          @matrix[i][j] = [@matrix[i - 1][j], @matrix[i][j - 1]].max
        end
      end
    end
  end

  def trace_back
    i, j = @seq1.length, @seq2.length
    align1, align2 = '', ''
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        align1 = @seq1[i - 1] + align1
        align2 = @seq2[j - 1] + align2
        i -= 1
        j -= 1
      elsif @matrix[i - 1][j] > @matrix[i][j - 1]
        align1 = @seq1[i - 1] + align1
        align2 = '-' + align2
        i -= 1
      else
        align1 = '-' + align1
        align2 = @seq2[j - 1] + align2
        j -= 1
      end
    end
    while i > 0
      align1 = @seq1[i - 1] + align1
      align2 = '-' + align2
      i -= 1
    end
    while j > 0
      align1 = '-' + align1
      align2 = @seq2[j - 1] + align2
      j -= 1
    end
    [align1, align2]
  end
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.build_matrix
  aligned_seq1, aligned_seq2 = aligner.trace_back
  puts "Aligned Sequence 1: #{aligned_seq1}"
  puts "Aligned Sequence 2: #{aligned_seq2}"
end

main