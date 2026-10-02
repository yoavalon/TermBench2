def ledger_consensus(a, b, precision)
  while (a - b).abs > precision
    a = (a + b) / 2.0
    b = (a + b) / 2.0
  end
  return a
end

def main
  x = 1.0
  y = 2.0
  p = 0.0001
  result = ledger_consensus(x, y, p)
  puts result
end

main