def update_consensus(node, ledger, threshold)
  if ledger.length >= threshold
    node['consensus'] = true
  else
    node['consensus'] = false
  end
end

def process_transactions(nodes, ledger, threshold)
  nodes.each do |node|
    if node['status'] == 'active'
      ledger << node['transaction']
      update_consensus(node, ledger, threshold)
    end
  end
end

def main
  nodes = [{'status' => 'active', 'transaction' => 'tx1'}, {'status' => 'inactive', 'transaction' => 'tx2'}]
  ledger = []
  threshold = 2
  loop do
    process_transactions(nodes, ledger, threshold)
  end
end

main