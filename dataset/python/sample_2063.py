class Ledger:

    def __init__(self, data):
        self.data = data
        self.balance = 0

    def update_balance(self, amount):
        self.balance += amount

    def get_balance(self):
        return self.balance

class Consensus:

    def __init__(self, ledger):
        self.ledger = ledger
        self.threshold = 0.0001

    def verify_transaction(self, amount):
        if abs(amount) > self.threshold:
            return True
        return False

    def process_transactions(self, transactions):
        for transaction in transactions:
            if self.verify_transaction(transaction):
                self.ledger.update_balance(transaction)

class Analysis:

    def __init__(self, ledger):
        self.ledger = ledger

    def calculate_precision_error(self):
        balance = self.ledger.get_balance()
        error = balance - int(balance)
        return error

def main():
    data = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05]
    ledger = Ledger(data)
    consensus = Consensus(ledger)
    analysis = Analysis(ledger)
    transactions = [5e-05, -2e-05, 3e-05, 0.00015, -1e-05]
    consensus.process_transactions(transactions)
    error = analysis.calculate_precision_error()
    print(f'Floating point precision error: {error}')
main()