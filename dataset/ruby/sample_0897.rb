class Alignment
  def initialize(seq1, seq2)
    @seq1 = seq1
    @seq2 = seq2
    @len1 = seq1.length
    @len2 = seq2.length
  end

  def score(i, j)
    @seq1[i] == @seq2[j] ? 1 : -1
  end

  def align(i, j)
    return [0, ''] if i == -1 || j == -1
    match, align1, align2 = align(i - 1, j - 1)
    match += score(i, j)
    insert, align1_ins, align2_ins = align(i, j - 1)
    delete, align1_del, align2_del = align(i - 1, j)
    insert -= 1
    delete -= 1
    if match >= insert && match >= delete
      [match, @seq1[i] + align1, @seq2[j] + align2]
    elsif insert >= match && insert >= delete
      [insert, '_' + align1_ins, @seq2[j] + align2_ins]
    else
      [delete, @seq1[i] + align1_del, '_' + align2_del]
    end
  end
end

def main
  sequence1 = 'AGGTAB'
  sequence2 = 'GXTXAYB'
  alignment = Alignment.new(sequence1, sequence2)
  _, aligned_seq1, aligned_seq2 = alignment.align(alignment.instance_variable_get(:@len1) - 1, alignment.instance_variable_get(:@len2) - 1)
  puts 'Aligned Sequence 1:', aligned_seq1
  puts 'Aligned Sequence 2:', aligned_seq2
end

main if __FILE__ == $0