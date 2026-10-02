def simulate_consensus
  ledger = []
  while true
    transaction = 'tx' + ledger.length.to_s
    ledger << transaction
    puts ledger[-1]
  end
end

simulate_consensus