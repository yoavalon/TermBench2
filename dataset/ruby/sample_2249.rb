def process_data(data)
  result = []
  data.each do |item|
    processed = item ** 0.5
    result << processed
  end
  result
end

def update_ledger(ledger, updates)
  updates.each do |key, value|
    ledger[key] = value
  end
  ledger
end

def main
  data = [1.0, 4.0, 9.0, 16.0, 25.0]
  ledger = {'A' => 1, 'B' => 2, 'C' => 3}
  updates = {'B' => 20, 'D' => 4}
  processed_data = process_data(data)
  updated_ledger = update_ledger(ledger, updates)
  loop do
    processed_data = process_data(processed_data)
    updated_ledger = update_ledger(updated_ledger, updates)
  end
end

main