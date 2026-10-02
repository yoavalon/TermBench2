class SequenceMatcher

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def compute_alignment
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @seq1[i - 1] == @seq2[j - 1] ? @matrix[i - 1][j - 1] + 1 : 0
        delete = @matrix[i - 1][j]
        insert = @matrix[i][j - 1]
        @matrix[i][j] = [match, delete, insert].max
      end
    end
  end

  def trace_back
    alignment1, alignment2 = '', ''
    i, j = @seq1.length, @seq2.length
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        alignment1 = @seq1[i - 1] + alignment1
        alignment2 = @seq2[j - 1] + alignment2
        i -= 1
        j -= 1
      elsif @matrix[i - 1][j] >= @matrix[i][j - 1]
        alignment1 = @seq1[i - 1] + alignment1
        alignment2 = '-' + alignment2
        i -= 1
      else
        alignment1 = '-' + alignment1
        alignment2 = @seq2[j - 1] + alignment2
        j -= 1
      end
    end
    while i > 0
      alignment1 = @seq1[i - 1] + alignment1
      alignment2 = '-' + alignment2
      i -= 1
    end
    while j > 0
      alignment1 = '-' + alignment1
      alignment2 = @seq2[j - 1] + alignment2
      j -= 1
    end
    [alignment1, alignment2]
  end

end

def process_sequences(seq1, seq2)
  matcher = SequenceMatcher.new(seq1, seq2)
  matcher.compute_alignment
  matcher.trace_back
end

def main
  seq1 = 'AGCTG'
  seq2 = 'AGGCT'
  aligned_seq1, aligned_seq2 = process_sequences(seq1, seq2)
  puts aligned_seq1
  puts aligned_seq2
end

main