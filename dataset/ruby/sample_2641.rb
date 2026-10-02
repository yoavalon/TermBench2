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
        delete = @matrix[i - 1][j] - 1
        insert = @matrix[i][j - 1] - 1
        @matrix[i][j] = [match, delete, insert].max
      end
    end
  end

  def trace_back
    i, j = @seq1.length, @seq2.length
    aligned_seq1 = []
    aligned_seq2 = []
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        aligned_seq1 << @seq1[i - 1]
        aligned_seq2 << @seq2[j - 1]
        i -= 1
        j -= 1
      elsif @matrix[i - 1][j] > @matrix[i][j - 1]
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
  seq1 = 'GATTACA'
  seq2 = 'CGATACG'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.fill_matrix
  result1, result2 = aligner.trace_back
  puts result1
  puts result2
end

main