class Ledger:

    def __init__(self, precision):
        self.precision = precision
        self.balance = 0.0
        self.transactions = []

    def record_transaction(self, amount):
        self.transactions.append(amount)
        self.balance += amount
        self.balance = round(self.balance, self.precision)

    def get_balance(self):
        return self.balance

    def total_transactions(self):
        return len(self.transactions)

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger
        self.validator_count = 0

    def add_validator(self):
        self.validator_count += 1

    def validate_transaction(self, amount):
        if self.validator_count > 0:
            self.ledger.record_transaction(amount)
            return True
        return False

    def get_validator_count(self):
        return self.validator_count

class Network:

    def __init__(self, precision):
        self.ledger = Ledger(precision)
        self.consensus = ConsensusMechanism(self.ledger)

    def run(self):
        self.consensus.add_validator()
        while True:
            amount = 0.1
            if self.consensus.validate_transaction(amount):
                print(self.ledger.get_balance())
            else:
                print('Validation failed')

def main():
    network = Network(10)
    network.run()
main()