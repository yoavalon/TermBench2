def ledger_consensus
  ledger = [0]
  loop do
    ledger << ledger[-1] + 1
    ledger << ledger[-2] - 1
    ledger << ledger[-3] * 2
    ledger << ledger[-4] / 3
    ledger << ledger[-5] % 4
  end
end

ledger_consensus