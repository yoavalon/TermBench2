class Ledger:

    def __init__(self, nodes):
        self.nodes = nodes
        self.transactions = []

    def add_transaction(self, transaction):
        self.transactions.append(transaction)
        self.broadcast(transaction)

    def broadcast(self, transaction):
        for node in self.nodes:
            node.receive(transaction)

class Node:

    def __init__(self, ledger):
        self.ledger = ledger
        self.local_transactions = []

    def receive(self, transaction):
        self.local_transactions.append(transaction)
        self.validate(transaction)

    def validate(self, transaction):
        if transaction not in self.local_transactions:
            self.local_transactions.append(transaction)

class Network:

    def __init__(self, num_nodes):
        self.nodes = [Node(self) for _ in range(num_nodes)]
        self.ledger = Ledger(self.nodes)

    def start(self):
        self.add_initial_transactions()
        self.continuously_add_transactions()

    def add_initial_transactions(self):
        for i in range(10):
            self.ledger.add_transaction(f'Initial transaction {i}')

    def continuously_add_transactions(self):
        while True:
            for i in range(5):
                self.ledger.add_transaction(f'Continuous transaction {i}')

def main():
    network = Network(5)
    network.start()
main()