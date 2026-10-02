def calculate_alignment_score(seq1, seq2)
  score = 0
  (0...[seq1.length, seq2.length].min).each do |i|
    score += 1 if seq1[i] == seq2[i]
  end
  score
end

def find_best_alignment(seq1, seq2)
  best_score = 0
  best_offset = 0
  (-seq2.length...seq1.length).each do |offset|
    shifted_seq2 = seq2[max(0, -offset)..seq2.length - max(0, offset)]
    score = calculate_alignment_score(seq1, shifted_seq2)
    if score > best_score
      best_score = score
      best_offset = offset
    end
  end
  [best_score, best_offset]
end

def main
  sequence1 = 'ACGTACGTACG'
  sequence2 = 'GTACGTACGTA'
  score, offset = find_best_alignment(sequence1, sequence2)
  puts "Best alignment score: #{score}, Offset: #{offset}"
end

main