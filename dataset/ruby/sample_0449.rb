def update_node_state(node, ledger, consensus)
  if node['status'] == 'syncing'
    node['status'] = 'ready'
    ledger.each do |block|
      unless node['chain'].any? { |b| b['hash'] == block['hash'] }
        node['chain'] << block
      end
    end
    if node['chain'].length > consensus['threshold']
      consensus['status'] = 'reached'
    end
  end
end

def check_consensus(consensus, nodes)
  if consensus['status'] == 'reached'
    nodes.each do |node|
      node['status'] = 'stable'
    end
    consensus['status'] = 'stable'
  end
end

def main
  ledger = [{'hash': 'block1'}, {'hash': 'block2'}]
  consensus = {'threshold': 1, 'status': 'pending'}
  nodes = [{'status': 'syncing', 'chain': []}, {'status': 'syncing', 'chain': []}]
  loop do
    nodes.each do |node|
      update_node_state(node, ledger, consensus)
    end
    check_consensus(consensus, nodes)
  end
end

main