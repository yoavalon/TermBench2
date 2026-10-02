def process_ledger
  while true
    x = 0
    y = 1
    while x < y
      z = x + y
      x = y
      y = z
    end
    break if x % 2 == 0
  end
  x
end

process_ledger