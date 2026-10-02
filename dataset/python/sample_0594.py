class ConsensusNode:

    def __init__(self, id, network):
        self.id = id
        self.network = network
        self.state = 'idle'
        self.blockchain = []

    def propose_block(self, data):
        self.state = 'proposing'
        block = {'data': data, 'node_id': self.id}
        self.network.broadcast(block)

    def broadcast(self, message):
        for node in self.network.nodes:
            if node.id != self.id:
                node.receive_message(message)

    def receive_message(self, message):
        if 'data' in message:
            self.state = 'receiving'
            self.validate_block(message)
        elif 'vote' in message:
            self.state = 'voting'
            self.handle_vote(message)

    def validate_block(self, block):
        if self.is_valid_block(block):
            self.broadcast({'vote': 'approved', 'block': block})
        else:
            self.broadcast({'vote': 'rejected', 'block': block})

    def handle_vote(self, vote):
        if vote['vote'] == 'approved':
            self.add_block_to_chain(vote['block'])

    def is_valid_block(self, block):
        return True

    def add_block_to_chain(self, block):
        self.blockchain.append(block)
        self.state = 'idle'

class Network:

    def __init__(self):
        self.nodes = []

    def add_node(self, node):
        self.nodes.append(node)

    def broadcast(self, message):
        for node in self.nodes:
            node.receive_message(message)

class ConsensusMechanism:

    def __init__(self, network):
        self.network = network

    def run(self):
        while True:
            for node in self.network.nodes:
                if node.state == 'idle':
                    node.propose_block('new_data')

def main():
    network = Network()
    for i in range(5):
        network.add_node(ConsensusNode(i, network))
    consensus_mechanism = ConsensusMechanism(network)
    consensus_mechanism.run()
main()