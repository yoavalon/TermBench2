def align(a, b, i, j)
  if i == 0 || j == 0
    return 0
  end
  if a[i - 1] == b[j - 1]
    return 1 + align(a, b, i - 1, j - 1)
  else
    return [align(a, b, i - 1, j), align(a, b, i, j - 1)].max
  end
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  result = align(seq1, seq2, seq1.length, seq2.length)
  puts result
end

main