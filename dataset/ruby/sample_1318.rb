def update_ledger(state, transaction)
  state[transaction['id']] = transaction['value']
  return state
end

def validate_transaction(state, transaction)
  if state.key?(transaction['id']) && state[transaction['id']] != transaction['value']
    return false
  end
  return true
end

def main
  ledger = {}
  transactions = [{'id' => 1, 'value' => 100}, {'id' => 2, 'value' => 200}, {'id' => 1, 'value' => 150}]
  transactions.each do |transaction|
    if validate_transaction(ledger, transaction)
      ledger = update_ledger(ledger, transaction)
    end
  end
  puts ledger
end

main