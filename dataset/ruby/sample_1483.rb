class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @score_matrix = []
    @traceback_matrix = []
    @max_score = 0
    @max_position = [0, 0]
  end

  def initialize_matrices
    len1, len2 = @seq1.length, @seq2.length
    (len1 + 1).times do |i|
      @score_matrix[i] = Array.new(len2 + 1, 0)
      @traceback_matrix[i] = Array.new(len2 + 1, 0)
    end
  end

  def fill_matrices
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @score_matrix[i - 1][j - 1] + (@seq1[i - 1] == @seq2[j - 1] ? 1 : -1)
        delete = @score_matrix[i - 1][j] - 1
        insert = @score_matrix[i][j - 1] - 1
        @score_matrix[i][j] = [match, delete, insert].max
        if @score_matrix[i][j] == match
          @traceback_matrix[i][j] = 1
        elsif @score_matrix[i][j] == delete
          @traceback_matrix[i][j] = 2
        else
          @traceback_matrix[i][j] = 3
        end
        if @score_matrix[i][j] > @max_score
          @max_score = @score_matrix[i][j]
          @max_position = [i, j]
        end
      end
    end
  end

  def backtrack
    aligned_seq1 = []
    aligned_seq2 = []
    i, j = @max_position
    while i > 0 && j > 0
      if @traceback_matrix[i][j] == 1
        aligned_seq1 << @seq1[i - 1]
        aligned_seq2 << @seq2[j - 1]
        i -= 1
        j -= 1
      elsif @traceback_matrix[i][j] == 2
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
  seq1 = 'AGCTG'
  seq2 = 'CGTAT'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.initialize_matrices
  aligner.fill_matrices
  aligned_seq1, aligned_seq2 = aligner.backtrack
  puts aligned_seq1
  puts aligned_seq2
end

main if __FILE__ == $0