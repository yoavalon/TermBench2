def ledger_consensus
  x = 1.0
  loop do
    x += 0.1
    if x >= 2.0
      x -= 2.0
    end
    puts x
  end
end

ledger_consensus