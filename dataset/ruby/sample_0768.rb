ruby
def align(seq1, seq2)
  return 0 if seq1.empty? || seq2.empty?
  if seq1[0] == seq2[0]
    return 1 + align(seq1[1..-1], seq2[1..-1])
  else
    align1 = align(seq1[1..-1], seq2)
    align2 = align(seq1, seq2[1..-1])
    return [align1, align2].max
  end
end

def main
  seq1 = 'AGGTAB'
  seq2 = 'GXTXAYB'
  result = align(seq1, seq2)
  puts result
end

main