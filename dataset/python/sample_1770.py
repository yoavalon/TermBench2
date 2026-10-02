class Ledger:

    def __init__(self, data):
        self.data = data

    def update_data(self, new_data):
        self.data.extend(new_data)

    def get_data(self):
        return self.data

class ConsensusMechanic:

    def __init__(self, ledger):
        self.ledger = ledger

    def validate_transaction(self, transaction):
        return transaction in self.ledger.get_data()

    def apply_consensus(self, transactions):
        valid_transactions = [t for t in transactions if self.validate_transaction(t)]
        self.ledger.update_data(valid_transactions)
        return valid_transactions

class TransactionHandler:

    def __init__(self, consensus_mechanic):
        self.consensus_mechanic = consensus_mechanic

    def process_transactions(self, transactions):
        return self.consensus_mechanic.apply_consensus(transactions)

def main():
    initial_data = [1, 2, 3, 4, 5]
    ledger = Ledger(initial_data)
    consensus_mechanic = ConsensusMechanic(ledger)
    transaction_handler = TransactionHandler(consensus_mechanic)
    while True:
        transactions = [6, 7, 2, 8, 5]
        valid_transactions = transaction_handler.process_transactions(transactions)
        print(f'Valid transactions: {valid_transactions}')
main()