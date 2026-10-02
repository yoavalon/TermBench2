class Alignment
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
    fill_matrix
    traceback
  end

  def fill_matrix
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @matrix[i - 1][j - 1] + 1 if @seq1[i - 1] == @seq2[j - 1] else 0
        delete = @matrix[i - 1][j] - 1
        insert = @matrix[i][j - 1] - 1
        @matrix[i][j] = [match, delete, insert].max
      end
    end
  end

  def traceback
    i, j = @seq1.length, @seq2.length
    align1, align2 = '', ''
    while i > 0 || j > 0
      if i > 0 && j > 0 && @matrix[i][j] == @matrix[i - 1][j - 1] + 1 && @seq1[i - 1] == @seq2[j - 1]
        align1 = @seq1[i - 1] + align1
        align2 = @seq2[j - 1] + align2
        i -= 1
        j -= 1
      elsif i > 0 && (j == 0 || @matrix[i][j] == @matrix[i - 1][j] - 1)
        align1 = @seq1[i - 1] + align1
        align2 = '-' + align2
        i -= 1
      else
        align1 = '-' + align1
        align2 = @seq2[j - 1] + align2
        j -= 1
      end
    end
    @result = [align1, align2]
  end
end

def main
  seq1 = 'AGTACGCA'
  seq2 = 'GTTAC'
  alignment = Alignment.new(seq1, seq2)
  puts "Sequence 1: #{alignment.result[0]}"
  puts "Sequence 2: #{alignment.result[1]}"
end

main