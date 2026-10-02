class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
    @score = 0
  end

  def fill_matrix
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @matrix[i - 1][j - 1] + (@seq1[i - 1] == @seq2[j - 1] ? 2 : -1)
        delete = @matrix[i - 1][j] - 1
        insert = @matrix[i][j - 1] - 1
        @matrix[i][j] = [match, delete, insert].max
      end
    end
  end

  def trace_back
    i, j = @seq1.length, @seq2.length
    aligned_seq1 = ''
    aligned_seq2 = ''
    while i > 0 || j > 0
      if i > 0 && j > 0 && @seq1[i - 1] == @seq2[j - 1]
        aligned_seq1 = @seq1[i - 1] + aligned_seq1
        aligned_seq2 = @seq2[j - 1] + aligned_seq2
        i -= 1
        j -= 1
      elsif i > 0 && @matrix[i][j] == @matrix[i - 1][j] - 1
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
  seq1 = 'AGTACGCA'
  seq2 = 'TATGC'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.fill_matrix
  aligned_seq1, aligned_seq2 = aligner.trace_back
  puts "Aligned Sequence 1: #{aligned_seq1}"
  puts "Aligned Sequence 2: #{aligned_seq2}"
end

main