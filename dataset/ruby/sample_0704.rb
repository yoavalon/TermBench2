def align(seq1, seq2, i, j, mem)
  return 0 if i == 0 || j == 0
  return mem[[i, j]] if mem.key?([i, j])
  if seq1[i - 1] == seq2[j - 1]
    result = 1 + align(seq1, seq2, i - 1, j - 1, mem)
  else
    result = [align(seq1, seq2, i - 1, j, mem), align(seq1, seq2, i, j - 1, mem)].max
  end
  mem[[i, j]] = result
  return result
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  i = seq1.length
  j = seq2.length
  mem = {}
  puts align(seq1, seq2, i, j, mem)
end

main