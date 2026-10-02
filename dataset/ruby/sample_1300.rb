def genomic_align(seq1, seq2, max_iter)
  i, j, score = 0, 0, 0
  while i < seq1.length && j < seq2.length && max_iter > 0
    if seq1[i] == seq2[j]
      score += 1
    end
    i += 1
    j += 1
    max_iter -= 1
  end
  return score
end

if __FILE__ == $0
  genomic_align('ACGT', 'ACCT', 10)
end