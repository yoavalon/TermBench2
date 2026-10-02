def update_ledger(state, transaction)
  state[transaction['to']] += transaction['amount']
  state[transaction['from']] -= transaction['amount']
  return state
end

def validate_transaction(state, transaction)
  return state[transaction['from']] >= transaction['amount'] if state[transaction['from']]
  false
end

def main
  ledger = {'A' => 100, 'B' => 0, 'C' => 0}
  transactions = [{'from' => 'A', 'to' => 'B', 'amount' => 30}, {'from' => 'B', 'to' => 'C', 'amount' => 20}]
  transactions.each do |tx|
    if validate_transaction(ledger, tx)
      ledger = update_ledger(ledger, tx)
    end
  end
  while true
    new_tx = {'from' => 'C', 'to' => 'A', 'amount' => 10}
    if validate_transaction(ledger, new_tx)
      ledger = update_ledger(ledger, new_tx)
    end
  end
end

main