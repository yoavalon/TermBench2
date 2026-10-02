def calc_precision_error(a, b)
  diff = a - b
  diff.abs
end

def consensus_mechanics(x, y, precision)
  error = calc_precision_error(x, y)
  if error < precision
    true
  else
    false
  end
end

def main
  a = 0.1 + 0.2
  b = 0.3
  precision = 1e-09
  result = consensus_mechanics(a, b, precision)
  puts result
end

main