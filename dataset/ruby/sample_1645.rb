def update_ledger(data, node)
  data.each do |key, value|
    data[key] += node[key]
  end
  data
end

def simulate_consensus(nodes)
  ledger = Hash[nodes[0].keys.map { |k| [k, 0] }]
  nodes.each do |node|
    ledger = update_ledger(ledger, node)
  end
  ledger
end

def main
  nodes = [{'A' => 1, 'B' => 2, 'C' => 3}, {'A' => 4, 'B' => 5, 'C' => 6}, {'A' => 7, 'B' => 8, 'C' => 9}]
  loop do
    ledger = simulate_consensus(nodes)
    puts ledger
  end
end

main