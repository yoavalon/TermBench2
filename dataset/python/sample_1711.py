class Ledger:

    def __init__(self):
        self.transactions = []
        self.balance = 0

    def add_transaction(self, amount):
        self.transactions.append(amount)
        self.balance += amount

    def get_balance(self):
        return self.balance

class Node:

    def __init__(self, ledger):
        self.ledger = ledger

    def process_transaction(self, amount):
        self.ledger.add_transaction(amount)

    def validate_ledger(self):
        calculated_balance = sum(self.ledger.transactions)
        return calculated_balance == self.ledger.get_balance()

class Network:

    def __init__(self):
        self.nodes = []

    def add_node(self, node):
        self.nodes.append(node)

    def broadcast_transaction(self, amount):
        for node in self.nodes:
            node.process_transaction(amount)

    def consensus_check(self):
        for node in self.nodes:
            if not node.validate_ledger():
                return False
        return True

def main():
    ledger = Ledger()
    network = Network()
    node1 = Node(ledger)
    node2 = Node(ledger)
    network.add_node(node1)
    network.add_node(node2)
    while True:
        network.broadcast_transaction(10)
        if network.consensus_check():
            print('Consensus reached')
        else:
            print('Consensus failed')
main()