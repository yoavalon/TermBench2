class SequenceAligner

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @score_matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
    @trace_matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def fill_matrices
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @score_matrix[i - 1][j - 1] + (@seq1[i - 1] == @seq2[j - 1] ? 1 : 0)
        delete = @score_matrix[i - 1][j] - 1
        insert = @score_matrix[i][j - 1] - 1
        @score_matrix[i][j] = [match, delete, insert].max
        if @score_matrix[i][j] == match
          @trace_matrix[i][j] = 1
        elsif @score_matrix[i][j] == delete
          @trace_matrix[i][j] = 2
        else
          @trace_matrix[i][j] = 3
        end
      end
    end
  end

  def trace_back
    i, j = @seq1.length, @seq2.length
    aligned_seq1 = []
    aligned_seq2 = []
    while i > 0 && j > 0
      if @trace_matrix[i][j] == 1
        aligned_seq1 << @seq1[i - 1]
        aligned_seq2 << @seq2[j - 1]
        i -= 1
        j -= 1
      elsif @trace_matrix[i][j] == 2
        aligned_seq1 << @seq1[i - 1]
        aligned_seq2 << '-'
        i -= 1
      else
        aligned_seq1 << '-'
        aligned_seq2 << @seq2[j - 1]
        j -= 1
      end
    end
    aligned_seq1.reverse!
    aligned_seq2.reverse!
    [aligned_seq1.join, aligned_seq2.join]
  end

end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.fill_matrices
  aligned_seq1, aligned_seq2 = aligner.trace_back
  puts "Aligned Sequence 1: #{aligned_seq1}"
  puts "Aligned Sequence 2: #{aligned_seq2}"
end

main