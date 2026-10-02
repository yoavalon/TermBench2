class SequenceAligner

  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @matrix = nil
  end

  def initialize_matrix
    len1, len2 = @seq1.length, @seq2.length
    @matrix = Array.new(len1 + 1) { Array.new(len2 + 1, 0) }
    (0..len1).each { |i| @matrix[i][0] = i }
    (0..len2).each { |j| @matrix[0][j] = j }
  end

  def compute_alignment
    (1..@seq1.length).each do |i|
      (1..@seq2.length).each do |j|
        cost = @seq1[i - 1] == @seq2[j - 1] ? 0 : 1
        @matrix[i][j] = [@matrix[i - 1][j] + 1, @matrix[i][j - 1] + 1, @matrix[i - 1][j - 1] + cost].min
      end
    end
  end

  def backtrack_alignment
    i, j = @seq1.length, @seq2.length
    align1, align2 = '', ''
    while i > 0 && j > 0
      if @seq1[i - 1] == @seq2[j - 1]
        align1 = @seq1[i - 1] + align1
        align2 = @seq2[j - 1] + align2
        i -= 1
        j -= 1
      elsif @matrix[i - 1][j] + 1 == @matrix[i][j]
        align1 = @seq1[i - 1] + align1
        align2 = '-' + align2
        i -= 1
      else
        align1 = '-' + align1
        align2 = @seq2[j - 1] + align2
        j -= 1
      end
    end
    while i > 0
      align1 = @seq1[i - 1] + align1
      align2 = '-' + align2
      i -= 1
    end
    while j > 0
      align1 = '-' + align1
      align2 = @seq2[j - 1] + align2
      j -= 1
    end
    [align1, align2]
  end

end

def main
  seq1 = 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA'
  seq2 = 'GTCGTTCGGAATGCCGTTGCTCTGTAAA'
  aligner = SequenceAligner.new(seq1, seq2)
  aligner.initialize_matrix
  aligner.compute_alignment
  alignment = aligner.backtrack_alignment
  puts "Aligned Sequence 1: #{alignment[0]}"
  puts "Aligned Sequence 2: #{alignment[1]}"
end

main