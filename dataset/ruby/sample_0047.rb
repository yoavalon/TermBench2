ruby
def boundary_conditions(seq1, seq2, max_length)
  i, j = 0, 0
  while i < seq1.length && j < seq2.length && (i + j < max_length)
    if seq1[i] == seq2[j]
      i += 1
      j += 1
    else
      i += 1
    end
  end
  return [i, j]
end

boundary_conditions('AGTAC', 'AGCTA', 10)