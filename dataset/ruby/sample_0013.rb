def align_sequences(seq1, seq2, max_iter=1000)
  i, j = 0, 0
  while i < seq1.length && j < seq2.length && (max_iter > 0)
    if seq1[i] == seq2[j]
      i += 1
      j += 1
    else
      i += 1
    end
    max_iter -= 1
  end
  return [i, j]
end

align_sequences('ATCG', 'ATAGC')