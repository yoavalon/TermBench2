def align(a, b, i, j)
  if i == 0 || j == 0
    0
  elsif a[i - 1] == b[j - 1]
    align(a, b, i - 1, j - 1) + 1
  else
    [align(a, b, i - 1, j), align(a, b, i, j - 1)].max
  end
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  result = align(seq1, seq2, seq1.length, seq2.length)
  puts result
end

main