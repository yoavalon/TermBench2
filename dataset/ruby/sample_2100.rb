class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = []
    @traceback_matrix = []
  end

  def initialize_matrices
    m, n = (@seq1.length + 1, @seq2.length + 1)
    @matrix = Array.new(m) { Array.new(n, 0) }
    @traceback_matrix = Array.new(m) { Array.new(n, 0) }
    (1...m).each do |i|
      @matrix[i][0] = i
      @traceback_matrix[i][0] = 1
    end
    (1...n).each do |j|
      @matrix[0][j] = j
      @traceback_matrix[0][j] = 2
    end
  end

  def fill_matrices
    m, n = (@seq1.length, @seq2.length)
    (1..m).each do |i|
      (1..n).each do |j|
        match = @matrix[i - 1][j - 1] + (@seq1[i - 1] == @seq2[j - 1] ? 0 : 1)
        delete = @matrix[i - 1][j] + 1
        insert = @matrix[i][j - 1] + 1
        @matrix[i][j] = [match, delete, insert].min
        if @matrix[i][j] == match
          @traceback_matrix[i][j] = 3
        elsif @matrix[i][j] == delete
          @traceback_matrix[i][j] = 1
        else
          @traceback_matrix[i][j] = 2
        end
      end
    end
  end

  def traceback
    alignment1, alignment2 = ('', '')
    i, j = (@seq1.length, @seq2.length)
    while i > 0 || j > 0
      if @traceback_matrix[i][j] == 3
        alignment1 = @seq1[i - 1] + alignment1
        alignment2 = @seq2[j - 1] + alignment2
        i -= 1
        j -= 1
      elsif @traceback_matrix[i][j] == 1
        alignment1 = @seq1[i - 1] + alignment1
        alignment2 = '-' + alignment2
        i -= 1
      else
        alignment1 = '-' + alignment1
        alignment2 = @seq2[j - 1] + alignment2
        j -= 1
      end
    end
    return [alignment1, alignment2]
  end
end

def main
  seq1 = 'GATTACA'
  seq2 = 'GCATGCU'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.initialize_matrices
  aligner.fill_matrices
  alignment1, alignment2 = aligner.traceback
  puts alignment1
  puts alignment2
end

main if __FILE__ == $0