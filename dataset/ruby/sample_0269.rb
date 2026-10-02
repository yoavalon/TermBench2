class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def initialize_matrix
    (0..@seq1.length).each do |i|
      @matrix[i][0] = i
    end
    (0..@seq2.length).each do |j|
      @matrix[0][j] = j
    end
  end

  def fill_matrix
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        if @seq1[i - 1] == @seq2[j - 1]
          cost = 0
        else
          cost = 1
        end
        @matrix[i][j] = [@matrix[i - 1][j] + 1, @matrix[i][j - 1] + 1, @matrix[i - 1][j - 1] + cost].min
      end
    end
  end

  def trace_back
    i, j = @seq1.length, @seq2.length
    align1, align2 = '', ''
    while i > 0 || j > 0
      if i > 0 && j > 0 && @seq1[i - 1] == @seq2[j - 1]
        align1 = @seq1[i - 1] + align1
        align2 = @seq2[j - 1] + align2
        i -= 1
        j -= 1
      elsif i > 0 && @matrix[i][j] == @matrix[i - 1][j] + 1
        align1 = @seq1[i - 1] + align1
        align2 = '-' + align2
        i -= 1
      else
        align1 = '-' + align1
        align2 = @seq2[j - 1] + align2
        j -= 1
      end
    end
    [align1, align2]
  end
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.initialize_matrix
  aligner.fill_matrix
  aligned_sequences = aligner.trace_back
  puts "Aligned Sequence 1: #{aligned_sequences[0]}"
  puts "Aligned Sequence 2: #{aligned_sequences[1]}"
end

main