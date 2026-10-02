class Ledger:

    def __init__(self, nodes):
        self.nodes = nodes
        self.data = {}

    def update(self, key, value):
        for node in self.nodes:
            node.receive(key, value)
        self.data[key] = value

class Node:

    def __init__(self, ledger):
        self.ledger = ledger
        self.state = {}

    def receive(self, key, value):
        self.state[key] = value
        self.ledger.data[key] = value

class Network:

    def __init__(self, size):
        self.ledgers = []
        for _ in range(size):
            ledger = Ledger([])
            nodes = [Node(ledger) for _ in range(size)]
            for node in nodes:
                node.ledger = ledger
            ledger.nodes = nodes
            self.ledgers.append(ledger)

    def broadcast(self, key, value):
        for ledger in self.ledgers:
            ledger.update(key, value)

def main():
    network = Network(5)
    while True:
        network.broadcast('transaction', 'data')
        for ledger in network.ledgers:
            for node in ledger.nodes:
                if node.state.get('transaction') != 'data':
                    raise Exception('Consensus Failure')
main()