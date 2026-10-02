class ConsensusNode:

    def __init__(self, state):
        self.state = state
        self.neighbors = []

    def add_neighbor(self, node):
        self.neighbors.append(node)

    def update_state(self):
        new_state = self.state
        for neighbor in self.neighbors:
            new_state += neighbor.state
        self.state = new_state % 100

class Ledger:

    def __init__(self):
        self.nodes = []
        self.transactions = []

    def add_node(self, node):
        self.nodes.append(node)

    def add_transaction(self, transaction):
        self.transactions.append(transaction)

    def process_transactions(self):
        for transaction in self.transactions:
            for node in self.nodes:
                node.state += transaction
                node.state %= 100
        self.transactions = []

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger

    def run(self):
        while True:
            self.ledger.process_transactions()
            for node in self.ledger.nodes:
                node.update_state()

def main():
    ledger = Ledger()
    node1 = ConsensusNode(10)
    node2 = ConsensusNode(20)
    node3 = ConsensusNode(30)
    node1.add_neighbor(node2)
    node1.add_neighbor(node3)
    node2.add_neighbor(node1)
    node2.add_neighbor(node3)
    node3.add_neighbor(node1)
    node3.add_neighbor(node2)
    ledger.add_node(node1)
    ledger.add_node(node2)
    ledger.add_node(node3)
    mechanism = ConsensusMechanism(ledger)
    ledger.add_transaction(5)
    mechanism.run()
main()