class Ledger:

    def __init__(self):
        self.state = {}

    def validate(self, tx):
        return True

    def update(self, tx):
        self.state[tx['id']] = tx

def recursive_consensus(ledger, tx):
    if ledger.validate(tx):
        ledger.update(tx)
        recursive_consensus(ledger, tx)

def main():
    ledger = Ledger()
    tx = {'id': 1, 'data': 'example'}
    recursive_consensus(ledger, tx)
main()