def align(x, y)
  if x && y
    return align(x[1..-1], y[1..-1]) + (x[0] == y[0] ? 1 : 0)
  end
  return align(x, y[1..-1]) + align(x[1..-1], y)
end

def main
  a = 'ACGT'
  b = 'AGCT'
  result = align(a, b)
  puts result
end

main