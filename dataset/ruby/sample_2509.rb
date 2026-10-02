def compute_similarity(seq1, seq2)
  length = [seq1.length, seq2.length].min
  score = 0
  (0...length).each do |i|
    score += 1 if seq1[i] == seq2[i]
  end
  score.to_f / length
end

def align_sequences(seq1, seq2)
  max_score = 0
  best_alignment = [seq1, seq2]
  (0...seq2.length).each do |i|
    shifted_seq = seq2[i..-1] + seq2[0...i]
    score = compute_similarity(seq1, shifted_seq)
    if score > max_score
      max_score = score
      best_alignment = [seq1, shifted_seq]
    end
  end
  best_alignment
end

def main
  sequence1 = 'ACGTACGTAC'
  sequence2 = 'TACGTACGTA'
  aligned_sequences = align_sequences(sequence1, sequence2)
  puts "Aligned Sequences: #{aligned_sequences}"
end

main