class Ledger:

    def __init__(self, precision):
        self.transactions = []
        self.precision = precision

    def add_transaction(self, amount):
        if len(self.transactions) > self.precision:
            self.transactions.pop(0)
        self.transactions.append(amount)

    def get_average_transaction(self):
        if not self.transactions:
            return 0
        return sum(self.transactions) / len(self.transactions)

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger

    def update_ledger(self, new_amount):
        self.ledger.add_transaction(new_amount)

    def validate_transaction(self, amount):
        avg_transaction = self.ledger.get_average_transaction()
        return abs(amount - avg_transaction) < self.ledger.precision

class Network:

    def __init__(self, precision):
        self.ledger = Ledger(precision)
        self.consensus_mechanism = ConsensusMechanism(self.ledger)

    def process_transaction(self, amount):
        if self.consensus_mechanism.validate_transaction(amount):
            self.consensus_mechanism.update_ledger(amount)
            return True
        return False

def main():
    network = Network(5)
    amounts = [10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0]
    for amount in amounts:
        if not network.process_transaction(amount):
            print(f'Transaction {amount} rejected')
        else:
            print(f'Transaction {amount} accepted')
if __name__ == '__main__':
    main()