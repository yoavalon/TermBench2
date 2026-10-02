def ledger_update(balance, transaction)
  precision = 1e-10
  if transaction.abs < precision
    return balance
  end
  return balance + transaction
end

def consensus_mechanism(data)
  processed_data = []
  data.each do |entry|
    processed_data << ledger_update(0, entry)
  end
  return processed_data
end

def main
  data = [0.1, 0.2, -0.3, 0.4, -0.1, 0.2]
  loop do
    data = consensus_mechanism(data)
  end
end

main