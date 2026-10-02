def validate_node_status(node)
  node['status'] == 'active' && node['consensus'] == 'reached'
end

def process_ledger(ledger, threshold)
  ledger.each do |block|
    return false unless validate_node_status(block['node'])
    return false if block['transactions'] > threshold
  end
  true
end

def main
  ledger_data = [{'node' => {'status' => 'active', 'consensus' => 'reached'}, 'transactions' => 100}, {'node' => {'status' => 'active', 'consensus' => 'reached'}, 'transactions' => 200}, {'node' => {'status' => 'active', 'consensus' => 'reached'}, 'transactions' => 300}]
  threshold_value = 250
  result = process_ledger(ledger_data, threshold_value)
  puts result
end

main