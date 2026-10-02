class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = nil
  end

  def create_matrix
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def fill_matrix
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @matrix[i - 1][j - 1] + (@seq1[i - 1] == @seq2[j - 1] ? 1 : 0)
        delete = @matrix[i - 1][j] - 1
        insert = @matrix[i][j - 1] - 1
        @matrix[i][j] = [match, delete, insert].max
      end
    end
  end

  def trace_back
    i, j = @seq1.length, @seq2.length
    align1, align2 = [], []
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        align1 << @seq1[i - 1]
        align2 << @seq2[j - 1]
        i -= 1
        j -= 1
      elsif @matrix[i - 1][j] > @matrix[i][j - 1]
        align1 << @seq1[i - 1]
        align2 << '-'
        i -= 1
      else
        align1 << '-'
        align2 << @seq2[j - 1]
        j -= 1
      end
    end
    while i > 0
      align1 << @seq1[i - 1]
      align2 << '-'
      i -= 1
    end
    while j > 0
      align1 << '-'
      align2 << @seq2[j - 1]
      j -= 1
    end
    return [align1.reverse.join, align2.reverse.join]
  end
end

def main
  seq1 = 'GATTACA'
  seq2 = 'GCATGCU'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.create_matrix
  aligner.fill_matrix
  aligned_seq1, aligned_seq2 = aligner.trace_back
  puts aligned_seq1
  puts aligned_seq2
end

main