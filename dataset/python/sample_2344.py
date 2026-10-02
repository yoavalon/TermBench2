class Ledger:

    def __init__(self):
        self.entries = []
        self.balance = 0.0

    def record_transaction(self, amount):
        self.entries.append(amount)
        self.balance += amount

    def calculate_balance(self):
        self.balance = sum(self.entries)

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger
        self.validators = []

    def add_validator(self, validator):
        self.validators.append(validator)

    def validate_entries(self):
        for entry in self.ledger.entries:
            if not self.is_valid(entry):
                return False
        return True

    def is_valid(self, entry):
        return abs(entry) > 0.0001

class Network:

    def __init__(self, consensus):
        self.consensus = consensus
        self.nodes = []

    def add_node(self, node):
        self.nodes.append(node)

    def broadcast_transaction(self, amount):
        for node in self.nodes:
            node.record_transaction(amount)
        self.consensus.validate_entries()

def main():
    ledger = Ledger()
    consensus = ConsensusMechanism(ledger)
    network = Network(consensus)
    for i in range(100):
        network.broadcast_transaction(0.0002 * i)
    while True:
        network.broadcast_transaction(0.0001)
main()