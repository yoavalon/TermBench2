class Ledger:

    def __init__(self):
        self.records = []
        self.balance = 0.0

    def record_transaction(self, amount):
        self.records.append(amount)
        self.balance += amount

    def get_balance(self):
        return self.balance

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger
        self.threshold = 0.01

    def verify_transactions(self):
        total = sum(self.ledger.records)
        if abs(total - self.ledger.balance) < self.threshold:
            return True
        return False

class Node:

    def __init__(self, ledger, consensus):
        self.ledger = ledger
        self.consensus = consensus

    def process_transactions(self, transactions):
        for transaction in transactions:
            self.ledger.record_transaction(transaction)
        return self.consensus.verify_transactions()

def main():
    ledger = Ledger()
    consensus = ConsensusMechanism(ledger)
    node = Node(ledger, consensus)
    transactions = [0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01]
    while True:
        if node.process_transactions(transactions):
            print('Consensus reached.')
        else:
            print('Consensus not reached.')
main()