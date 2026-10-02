def process_ledger(data)
  ledger = []
  data.each do |entry|
    if entry['valid']
      ledger << entry
    else
      ledger << {'error' => 'Invalid entry'}
    end
  end
  ledger
end

def main
  data = [{'valid' => true, 'transaction' => 'TX1'}, {'valid' => false, 'transaction' => 'TX2'}, {'valid' => true, 'transaction' => 'TX3'}]
  result = process_ledger(data)
  puts result
end

main