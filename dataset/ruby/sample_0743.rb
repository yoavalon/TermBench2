def align(seq1, seq2, i, j, memo)
  if i == 0 || j == 0
    return [i, j].max
  end
  if memo[[i, j]]
    return memo[[i, j]]
  end
  if seq1[i - 1] == seq2[j - 1]
    memo[[i, j]] = align(seq1, seq2, i - 1, j - 1, memo)
  else
    memo[[i, j]] = 1 + [align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo), align(seq1, seq2, i - 1, j - 1, memo)].min
  end
  return memo[[i, j]]
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  memo = {}
  puts align(seq1, seq2, seq1.length, seq2.length, memo)
end

main