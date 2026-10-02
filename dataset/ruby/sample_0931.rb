def align(a, b, i=0, j=0)
  if i < a.length && j < b.length
    align(a, b, i + 1, j + 1)
  else
    align(a, b, i, j + 1)
    align(a, b, i + 1, j)
    align(a, b, i + 1, j + 1)
  end
end

align('ACGT', 'ACCGT')