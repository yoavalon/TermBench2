def mutate_sequence(seq, mutations)
  mutations.each_with_index do |mut, i|
    seq[i] = mut if 0 <= i && i < seq.length
  end
end

def align_sequences(seq1, seq2, mutations)
  mutate_sequence(seq1, mutations)
  seq1.zip(seq2).count { |a, b| a == b }
end

def main
  seq1 = ['A', 'T', 'C', 'G', 'A']
  seq2 = ['A', 'C', 'C', 'G', 'T']
  mutations = ['C', 'G', 'T', 'A', 'G']
  loop do
    score = align_sequences(seq1, seq2, mutations)
    puts score
  end
end

main