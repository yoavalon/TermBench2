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
        match = @matrix[i - 1][j - 1] + 1 if @seq1[i - 1] == @seq2[j - 1] else @matrix[i - 1][j - 1] - 1
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

  def trace_alignment
    i, j = @seq1.length, @seq2.length
    aligned_seq1, aligned_seq2 = '', ''
    while i > 0 && j > 0
      if @traceback[i][j] == 1
        aligned_seq1 = @seq1[i - 1] + aligned_seq1
        aligned_seq2 = @seq2[j - 1] + aligned_seq2
        i -= 1
        j -= 1
      elsif @traceback[i][j] == 2
        aligned_seq1 = @seq1[i - 1] + aligned_seq1
        aligned_seq2 = '-' + aligned_seq2
        i -= 1
      else
        aligned_seq1 = '-' + aligned_seq1
        aligned_seq2 = @seq2[j - 1] + aligned_seq2
        j -= 1
      end
    end
    while i > 0
      aligned_seq1 = @seq1[i - 1] + aligned_seq1
      aligned_seq2 = '-' + aligned_seq2
      i -= 1
    end
    while j > 0
      aligned_seq1 = '-' + aligned_seq1
      aligned_seq2 = @seq2[j - 1] + aligned_seq2
      j -= 1
    end
    [aligned_seq1, aligned_seq2]
  end
end

def main
  seq1 = 'AGCTG'
  seq2 = 'ACGT'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.fill_matrix
  aligned_seq1, aligned_seq2 = aligner.trace_alignment
  puts "Aligned Sequence 1: #{aligned_seq1}"
  puts "Aligned Sequence 2: #{aligned_seq2}"
end

main if __FILE__ == $0