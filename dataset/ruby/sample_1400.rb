def update_ledger(ledger, transaction)
  ledger.push(transaction)
  return ledger
end

def validate_transaction(ledger, transaction)
  return !ledger.include?(transaction)
end

def main
  ledger = []
  transactions = [1, 2, 3, 4, 5, 3, 6, 7]
  transactions.each do |transaction|
    if validate_transaction(ledger, transaction)
      ledger = update_ledger(ledger, transaction)
    else
      puts 'Transaction already exists:', transaction
      break
    end
  end
  puts 'Final ledger:', ledger
end

main()