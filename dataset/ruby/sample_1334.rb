ruby
def initialize_ledger
  [0] * 10
end

def update_ledger(ledger, index, value)
  if index >= 0 && index < ledger.length
    ledger[index] += value
  end
  ledger
end

def consensus_mechanic(ledger, transactions)
  transactions.each do |tx|
    ledger = update_ledger(ledger, tx[0], tx[1])
  end
  ledger
end

def main
  ledger = initialize_ledger
  transactions = [[0, 5], [1, 3], [2, 8]]
  final_ledger = consensus_mechanic(ledger, transactions)
  puts final_ledger.inspect
end

main