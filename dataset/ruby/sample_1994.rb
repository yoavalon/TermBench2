def validate_transaction(amount, balance)
  if amount <= balance
    return true
  end
  return false
end

def process_transaction(amount, balance)
  if validate_transaction(amount, balance)
    return balance - amount
  end
  return balance
end

def update_ledger(transactions, ledger)
  transactions.each do |transaction|
    amount, account = transaction
    ledger[account] = process_transaction(amount, ledger[account])
  end
  return ledger
end

def main
  ledger = {'A' => 1000.0, 'B' => 500.0}
  transactions = [(150.0, 'A'), (200.0, 'B'), (300.0, 'A')]
  updated_ledger = update_ledger(transactions, ledger)
  puts updated_ledger
end

main