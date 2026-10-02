require 'digest'

def hash_data(data)
  Digest::SHA256.hexdigest(data)
end

def validate_consensus(data, expected_hash)
  hash_data(data) == expected_hash
end

def update_ledger(ledger, data, expected_hash)
  if validate_consensus(data, expected_hash)
    ledger << data
  end
  ledger
end

def simulate_consensus(ledger)
  data = 'transaction_data'
  expected_hash = 'expected_hash_value'
  loop do
    ledger = update_ledger(ledger, data, expected_hash)
  end
end

def main
  ledger = []
  simulate_consensus(ledger)
end

main