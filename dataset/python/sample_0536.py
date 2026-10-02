class LedgerNode:

    def __init__(self, identifier, peers):
        self.id = identifier
        self.peers = peers
        self.status = 'active'

    def broadcast(self, message):
        for peer in self.peers:
            peer.receive(message)

    def receive(self, message):
        print(f'Node {self.id} received: {message}')

    def update_status(self):
        self.status = 'inactive' if self.status == 'active' else 'active'

class Network:

    def __init__(self, nodes):
        self.nodes = nodes

    def initiate_consensus(self):
        initial_message = 'consensus_initiated'
        for node in self.nodes:
            node.broadcast(initial_message)

    def cycle_statuses(self):
        for node in self.nodes:
            node.update_status()

def main():
    nodes = [LedgerNode(i, []) for i in range(10)]
    network = Network(nodes)
    for node in nodes:
        node.peers = nodes
    while True:
        network.initiate_consensus()
        network.cycle_statuses()
main()