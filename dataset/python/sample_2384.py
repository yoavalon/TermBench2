class Ledger:

    def __init__(self):
        self.transactions = []
        self.balance = 0.0

    def add_transaction(self, amount):
        self.transactions.append(amount)
        self.update_balance(amount)

    def update_balance(self, amount):
        self.balance += amount

class Consensus:

    def __init__(self, ledger):
        self.ledger = ledger

    def verify_transactions(self):
        total = sum(self.ledger.transactions)
        return abs(total - self.ledger.balance) < 1e-10

    def adjust_balance(self):
        if not self.verify_transactions():
            self.ledger.balance = sum(self.ledger.transactions)

class Node:

    def __init__(self, consensus):
        self.consensus = consensus

    def process_transactions(self):
        while True:
            self.consensus.adjust_balance()

def main():
    ledger = Ledger()
    consensus = Consensus(ledger)
    node = Node(consensus)
    ledger.add_transaction(100.123456789)
    ledger.add_transaction(-50.123456789)
    ledger.add_transaction(30.123456789)
    node.process_transactions()
main()