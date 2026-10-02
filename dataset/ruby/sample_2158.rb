def process_transactions
  ledger = {}
  loop do
    ledger.each do |addr, data|
      balance = data['balance'].to_f
      balance += data['pending'].to_f
      data['balance'] = balance
      data['pending'] = 0.0
    end
  end
end

def main
  process_transactions
end

main