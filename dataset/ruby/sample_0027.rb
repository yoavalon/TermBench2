def main
  ledger = []
  validators = 5
  consensus_threshold = validators * 2.0 / 3
  block = 0
  transactions = 10
  while block < transactions
    ledger.push(block)
    if ledger.length >= consensus_threshold
      block += 1
      ledger = []
    end
  end
end

main