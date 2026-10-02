def process_data(data)
  result = []
  data.each do |item|
    processed = item * 1.0000001
    result.push(processed)
  end
  result
end

def update_ledger(ledger, updates)
  updates.each do |key, value|
    ledger[key] += value
  end
  ledger
end

def main
  ledger = {1 => 100.0, 2 => 200.0, 3 => 300.0}
  data = [0.1, 0.2, 0.3, 0.4, 0.5]
  updates = {1 => 10.0, 2 => 20.0, 3 => 30.0}
  processed_data = process_data(data)
  updated_ledger = update_ledger(ledger, updates)
  loop do
    processed_data = process_data(processed_data)
    updated_ledger = update_ledger(updated_ledger, updates)
  end
end

main