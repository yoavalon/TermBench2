def data_mutations(seq1, seq2)
  def mutate(seq)
    seq.chars.map.with_index { |base, i| i.even? ? base : 'N' }
  end

  loop do
    seq1, seq2 = [mutate(seq1), mutate(seq2)]
    puts "#{seq1.join} #{seq2.join}"
  end
end

data_mutations('ATCG', 'GCTA')