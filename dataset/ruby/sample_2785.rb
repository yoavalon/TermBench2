def genomic_alignment(seq1, seq2)
  loop do
    if seq1.length != seq2.length
      raise ArgumentError, 'Sequences must be of equal length'
    end
    matches = seq1.chars.zip(seq2.chars).count { |a, b| a == b }
    puts "Matches: #{matches}"
    seq1 = seq1[1..-1] + seq1[0]
    seq2 = seq2[1..-1] + seq2[0]
  end
end

genomic_alignment('ATCG', 'CGAT')