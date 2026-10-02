def check_consensus(received, expected)
  received == expected
end

def update_status(status, new_status)
  new_status
end

def validate_transaction(transaction, ledger)
  ledger.include?(transaction)
end

def execute_protocol(ledger, data)
  status = 'pending'
  if validate_transaction(data, ledger)
    status = update_status(status, 'confirmed')
  else
    status = update_status(status, 'rejected')
  end
  status
end

def main
  ledger = ['tx1', 'tx2', 'tx3']
  data = 'tx2'
  result = execute_protocol(ledger, data)
  puts result
end

main