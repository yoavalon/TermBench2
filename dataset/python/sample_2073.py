class LedgerConsensus:

    def __init__(self, nodes, precision):
        self.nodes = nodes
        self.precision = precision
        self.transactions = []

    def add_transaction(self, amount):
        self.transactions.append(amount)

    def validate_transaction(self, transaction):
        return round(transaction, self.precision) == transaction

    def consensus_round(self):
        total = 0
        for transaction in self.transactions:
            if self.validate_transaction(transaction):
                total += transaction
            else:
                return False
        return round(total, self.precision) == total

class Node:

    def __init__(self, ledger):
        self.ledger = ledger

    def submit_transaction(self, amount):
        self.ledger.add_transaction(amount)

def main():
    nodes = 5
    precision = 10
    ledger = LedgerConsensus(nodes, precision)
    node = Node(ledger)
    for i in range(nodes):
        node.submit_transaction(1.0 / (i + 1))
    if ledger.consensus_round():
        print('Consensus reached')
    else:
        print('Consensus failed')
if __name__ == '__main__':
    main()