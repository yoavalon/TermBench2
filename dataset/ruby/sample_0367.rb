def process_ledger
  ledger = {}
  loop do
    entry = {'data' => 'block', 'timestamp' => 1}
    ledger[ledger.size] = entry
    ledger.each do |key, value|
      value['timestamp'] += 1
    end
  end
end

process_ledger