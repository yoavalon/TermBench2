def align(seq1, seq2, i, j, memo)
  if memo.key?([i, j])
    return memo[[i, j]]
  end
  if i == seq1.length || j == seq2.length
    return 0
  end
  match = align(seq1, seq2, i + 1, j + 1, memo) + (seq1[i] == seq2[j] ? 1 : 0)
  delete = align(seq1, seq2, i + 1, j, memo)
  insert = align(seq1, seq2, i, j + 1, memo)
  result = [match, delete, insert].max
  memo[[i, j]] = result
  return result
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  memo = {}
  puts align(seq1, seq2, 0, 0, memo)
end

main