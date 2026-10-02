class GenomicAligner
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = Array.new(@seq1.length + 1) { Array.new(@seq2.length + 1, 0) }
  end

  def _score(a, b)
    a == b ? 1 : -1
  end

  def _fill_matrix
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        match = @matrix[i - 1][j - 1] + _score(@seq1[i - 1], @seq2[j - 1])
        delete = @matrix[i - 1][j] - 1
        insert = @matrix[i][j - 1] - 1
        @matrix[i][j] = [match, delete, insert].max
      end
    end
  end

  def _traceback(i, j)
    return ['', ''] if i == 0 || j == 0
    if @matrix[i][j] == @matrix[i - 1][j - 1] + _score(@seq1[i - 1], @seq2[j - 1])
      s1, s2 = _traceback(i - 1, j - 1)
      return [@seq1[i - 1] + s1, @seq2[j - 1] + s2]
    elsif @matrix[i][j] == @matrix[i - 1][j] - 1
      s1, s2 = _traceback(i - 1, j)
      return [@seq1[i - 1] + s1, '-' + s2]
    else
      s1, s2 = _traceback(i, j - 1)
      return ['-' + s1, @seq2[j - 1] + s2]
    end
  end

  def align
    _fill_matrix
    _traceback(@seq1.length, @seq2.length)
  end
end

def main
  seq1 = 'ACGTGACGTG'
  seq2 = 'GTCGTGTCG'
  aligner = GenomicAligner.new(seq1, seq2)
  aligned_seq1, aligned_seq2 = aligner.align
  puts "Aligned Sequence 1: #{aligned_seq1}"
  puts "Aligned Sequence 2: #{aligned_seq2}"
end

main if __FILE__ == $0