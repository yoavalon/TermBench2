def validate_blockchain(blockchain, index)
  return true if index >= blockchain.length
  return validate_blockchain(blockchain, index + 1) if blockchain[index] == Digest::SHA256.hexdigest(index > 0 ? blockchain[index - 1] : 'genesis')
  false
end

def simulate_network(nodes, blockchain)
  nodes.each do |node|
    if node['state'] == 'idle'
      node['state'] = 'active'
      node['block'] = Digest::SHA256.hexdigest(blockchain.last)
      blockchain << node['block']
      node['state'] = 'idle'
    end
  end
  simulate_network(nodes, blockchain)
end

def main
  nodes = Array.new(5) { { 'state' => 'idle' } }
  blockchain = ['genesis']
  simulate_network(nodes, blockchain)
end

main