class GenomicAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def _fill_matrix
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

  def _traceback
    alignment1 = []
    alignment2 = []
    i, j = @seq1.length, @seq2.length
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        alignment1 << @seq1[i - 1]
        alignment2 << @seq2[j - 1]
        i -= 1
        j -= 1
      elsif @matrix[i - 1][j] > @matrix[i][j - 1]
        alignment1 << @seq1[i - 1]
        alignment2 << '-'
        i -= 1
      else
        alignment1 << '-'
        alignment2 << @seq2[j - 1]
        j -= 1
      end
    end
    alignment1.reverse!
    alignment2.reverse!
    return [alignment1, alignment2]
  end

  def align
    _fill_matrix
    _traceback
  end
end

def main
  seq1 = 'AGTACGCA'
  seq2 = 'TGACGTCA'
  aligner = GenomicAligner.new(seq1, seq2)
  result = aligner.align
  puts "Alignment 1: #{result[0].join}"
  puts "Alignment 2: #{result[1].join}"
end

main if __FILE__ == $0