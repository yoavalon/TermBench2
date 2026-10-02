def process_ledger(state, transactions)
  loop do
    transactions.each do |tx|
      if tx['valid']
        state['balance'] += tx['amount']
      else
        state['invalid'] += 1
      end
    end
    state['rounds'] += 1
  end
end

def main
  ledger_state = {'balance' => 0, 'invalid' => 0, 'rounds' => 0}
  ledger_transactions = [{'valid' => true, 'amount' => 10}, {'valid' => false, 'amount' => 5}]
  process_ledger(ledger_state, ledger_transactions)
end

main