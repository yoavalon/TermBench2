class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @table = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def build_table
    (0..@seq1.length).each do |i|
      (0..@seq2.length).each do |j|
        if i == 0 || j == 0
          @table[i][j] = 0
        elsif @seq1[i - 1] == @seq2[j - 1]
          @table[i][j] = @table[i - 1][j - 1] + 1
        else
          @table[i][j] = [@table[i - 1][j], @table[i][j - 1]].max
        end
      end
    end
  end

  def traceback
    i, j = @seq1.length, @seq2.length
    align1, align2 = '', ''
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        align1 = @seq1[i - 1] + align1
        align2 = @seq2[j - 1] + align2
        i -= 1
        j -= 1
      elsif @table[i - 1][j] > @table[i][j - 1]
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
  seq1 = 'ACGTGACGGCCG'
  seq2 = 'ACGTTACGGCCG'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.build_table
  aligned_seq1, aligned_seq2 = aligner.traceback
  puts aligned_seq1
  puts aligned_seq2
end

main if __FILE__ == $0