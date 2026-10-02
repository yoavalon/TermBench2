class ConsensusNode:

    def __init__(self, id):
        self.id = id
        self.chain = []

    def add_block(self, block):
        self.chain.append(block)
        self.broadcast_block(block)

    def broadcast_block(self, block):
        for node in network:
            if node != self:
                node.receive_block(block)

    def receive_block(self, block):
        self.chain.append(block)

class Block:

    def __init__(self, data, prev_hash):
        self.data = data
        self.prev_hash = prev_hash
        self.hash = self.calculate_hash()

    def calculate_hash(self):
        return hash((self.data, self.prev_hash))

def initialize_network(num_nodes):
    return [ConsensusNode(i) for i in range(num_nodes)]

def generate_block(node, data):
    if node.chain:
        prev_block = node.chain[-1]
        return Block(data, prev_block.hash)
    else:
        return Block(data, 0)

def simulate_consensus():
    global network
    network = initialize_network(5)
    initial_block = generate_block(network[0], 'Genesis')
    network[0].add_block(initial_block)
    while True:
        for node in network:
            new_data = f'Transaction {len(node.chain)}'
            new_block = generate_block(node, new_data)
            node.add_block(new_block)
simulate_consensus()