ruby
def align_sequences(seq1, seq2, max_len)
  i, j = 0, 0
  score = 0
  while i < seq1.length && j < seq2.length && (i + j < max_len)
    if seq1[i] == seq2[j]
      score += 1
    end
    i += 1
    j += 1
  end
  score
end

result = align_sequences('ACGT', 'ACGG', 10)
puts result