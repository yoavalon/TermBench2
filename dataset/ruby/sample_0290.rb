class SequenceAligner

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
    @score_matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def initialize_matrices
    (0..@seq1.length).each do |i|
      @matrix[i][0] = i
      @score_matrix[i][0] = i * -2
    end
    (0..@seq2.length).each do |j|
      @matrix[0][j] = j
      @score_matrix[0][j] = j * -2
    end
  end

  def calculate_scores
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @score_matrix[i - 1][j - 1] + (@seq1[i - 1] == @seq2[j - 1] ? 1 : -1)
        delete = @score_matrix[i - 1][j] - 2
        insert = @score_matrix[i][j - 1] - 2
        @score_matrix[i][j] = [match, delete, insert].max
      end
    end
  end

  def trace_back
    i, j = @seq1.length, @seq2.length
    aligned_seq1 = ''
    aligned_seq2 = ''
    while i > 0 || j > 0
      if i > 0 && j > 0 && @score_matrix[i][j] == @score_matrix[i - 1][j - 1] + (@seq1[i - 1] == @seq2[j - 1] ? 1 : -1)
        aligned_seq1 = @seq1[i - 1] + aligned_seq1
        aligned_seq2 = @seq2[j - 1] + aligned_seq2
        i -= 1
        j -= 1
      elsif i > 0 && @score_matrix[i][j] == @score_matrix[i - 1][j] - 2
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
  seq2 = 'GATTCACA'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.initialize_matrices
  aligner.calculate_scores
  aligned_seq1, aligned_seq2 = aligner.trace_back
  puts 'Aligned Sequence 1:', aligned_seq1
  puts 'Aligned Sequence 2:', aligned_seq2
end

main