class Ledger:

    def __init__(self):
        self.transactions = []

    def add_transaction(self, transaction):
        self.transactions.append(transaction)

    def get_balance(self):
        balance = 0
        for transaction in self.transactions:
            balance += transaction
        return balance

class Node:

    def __init__(self, ledger):
        self.ledger = ledger

    def process_transaction(self, transaction):
        self.ledger.add_transaction(transaction)

class Network:

    def __init__(self, nodes):
        self.nodes = nodes

    def broadcast_transaction(self, transaction):
        for node in self.nodes:
            node.process_transaction(transaction)

def main():
    ledger = Ledger()
    node1 = Node(ledger)
    node2 = Node(ledger)
    network = Network([node1, node2])
    while True:
        transaction = 10
        network.broadcast_transaction(transaction)
        print('Current Balance:', ledger.get_balance())
main()