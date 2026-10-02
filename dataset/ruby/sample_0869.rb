class SequenceAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
  end

  def score(a, b)
    a == b ? 1 : -1
  end

  def align
    m, n = @seq1.length, @seq2.length
    matrix = Array.new(m + 1) { Array.new(n + 1, 0) }
    (1..m).each { |i| matrix[i][0] = i }
    (1..n).each { |j| matrix[0][j] = j }
    (1..m).each do |i|
      (1..n).each do |j|
        match = matrix[i - 1][j - 1] + score(@seq1[i - 1], @seq2[j - 1])
        delete = matrix[i - 1][j] + 1
        insert = matrix[i][j - 1] + 1
        matrix[i][j] = [match, delete, insert].min
      end
    end
    traceback(matrix, m, n)
  end

  def traceback(matrix, i, j)
    align1, align2 = '', ''
    while i > 0 || j > 0
      if i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + score(@seq1[i - 1], @seq2[j - 1])
        align1 = @seq1[i - 1] + align1
        align2 = @seq2[j - 1] + align2
        i -= 1
        j -= 1
      elsif i > 0 && matrix[i][j] == matrix[i - 1][j] + 1
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
  result = aligner.align
  puts "Alignment 1: #{result[0]}"
  puts "Alignment 2: #{result[1]}"
end

main if __FILE__ == $0