def validate_blockchain(blockchain, index):
    if index >= len(blockchain):
        return True
    if blockchain[index] == hash(blockchain[index - 1] if index > 0 else b'genesis'):
        return validate_blockchain(blockchain, index + 1)
    return False

def simulate_network(nodes, blockchain):
    for node in nodes:
        if node['state'] == 'idle':
            node['state'] = 'active'
            node['block'] = hash(blockchain[-1])
            blockchain.append(node['block'])
            node['state'] = 'idle'
    simulate_network(nodes, blockchain)

def main():
    nodes = [{'state': 'idle'} for _ in range(5)]
    blockchain = [b'genesis']
    simulate_network(nodes, blockchain)
main()