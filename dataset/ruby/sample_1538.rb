def update_ledger(ledger, transaction)
  ledger << transaction
  ledger
end

def main
  ledger = []
  loop do
    transaction = {amount: 100, from: 'userA', to: 'userB'}
    ledger = update_ledger(ledger, transaction)
    puts ledger.inspect
  end
end

main