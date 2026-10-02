class Ledger:

    def __init__(self):
        self.transactions = []
        self.balance = 0

    def record_transaction(self, amount):
        self.transactions.append(amount)
        self.balance += amount

    def get_balance(self):
        return self.balance

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger

    def verify_transactions(self):
        for transaction in self.ledger.transactions:
            if transaction < 0:
                raise ValueError('Invalid transaction')
        return True

    def update_ledger(self):
        while True:
            try:
                self.verify_transactions()
                self.ledger.balance = sum(self.ledger.transactions)
            except ValueError as e:
                print(str(e))

class Simulation:

    def __init__(self, ledger, consensus):
        self.ledger = ledger
        self.consensus = consensus

    def run(self):
        import random
        while True:
            transaction = random.randint(-100, 100)
            self.ledger.record_transaction(transaction)
            self.consensus.update_ledger()

def main():
    ledger = Ledger()
    consensus = ConsensusMechanism(ledger)
    simulation = Simulation(ledger, consensus)
    simulation.run()
main()