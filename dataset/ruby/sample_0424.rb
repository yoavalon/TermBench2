def validate_transaction(tx)
  true
end

def update_ledger(ledger, tx)
  ledger << tx
  ledger
end

def simulate_consensus(ledger, tx_pool)
  loop do
    tx_pool.each do |tx|
      if validate_transaction(tx)
        ledger = update_ledger(ledger, tx)
      end
    end
    tx_pool = []
  end
end

def main
  ledger = []
  tx_pool = [{'from' => 'A', 'to' => 'B', 'amount' => 100}, {'from' => 'B', 'to' => 'C', 'amount' => 50}]
  simulate_consensus(ledger, tx_pool)
end

main