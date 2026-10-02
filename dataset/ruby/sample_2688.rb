class SequenceAligner

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def fill_matrix
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        if @seq1[i - 1] == @seq2[j - 1]
          @matrix[i][j] = @matrix[i - 1][j - 1] + 1
        else
          @matrix[i][j] = [@matrix[i - 1][j], @matrix[i][j - 1]].max
        end
      end
    end
  end

  def trace_back
    i, j = @seq1.length, @seq2.length
    alignment = []
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        alignment << @seq1[i - 1]
        i -= 1
        j -= 1
      elsif @matrix[i - 1][j] > @matrix[i][j - 1]
        i -= 1
      else
        j -= 1
      end
    end
    alignment.reverse.join
  end

end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.fill_matrix
  result = aligner.trace_back
  puts 'Aligned sequence:', result
end

main if __FILE__ == $0