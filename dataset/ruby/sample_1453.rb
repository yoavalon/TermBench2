class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
    @traceback = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def fill_matrix
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @matrix[i - 1][j - 1] + (@seq1[i - 1] == @seq2[j - 1] ? 1 : 0)
        delete = @matrix[i - 1][j] - 1
        insert = @matrix[i][j - 1] - 1
        @matrix[i][j] = [match, delete, insert].max
        if @matrix[i][j] == match
          @traceback[i][j] = 1
        elsif @matrix[i][j] == delete
          @traceback[i][j] = 2
        else
          @traceback[i][j] = 3
        end
      end
    end
  end

  def align_sequences
    aligned_seq1 = ''
    aligned_seq2 = ''
    i, j = @seq1.length, @seq2.length
    while i > 0 || j > 0
      if i > 0 && j > 0 && @traceback[i][j] == 1
        aligned_seq1 = @seq1[i - 1] + aligned_seq1
        aligned_seq2 = @seq2[j - 1] + aligned_seq2
        i -= 1
        j -= 1
      elsif i > 0 && (j == 0 || @traceback[i][j] == 2)
        aligned_seq1 = @seq1[i - 1] + aligned_seq1
        aligned_seq2 = '-' + aligned_seq2
        i -= 1
      else
        aligned_seq1 = '-' + aligned_seq1
        aligned_seq2 = @seq2[j - 1] + aligned_seq2
        j -= 1
      end
    end
    [aligned_seq1, aligned_seq2]
  end
end

def main
  seq1 = 'GATTACA'
  seq2 = 'CGATTACG'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.fill_matrix
  aligned_seq1, aligned_seq2 = aligner.align_sequences
  puts aligned_seq1
  puts aligned_seq2
end

main