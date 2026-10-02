class SequenceGenerator:

    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.current = 0

    def next_value(self):
        self.current += 1
        return self.a * self.current + self.b

class LedgerSimulator:

    def __init__(self, sequence):
        self.sequence = sequence
        self.transactions = []

    def add_transaction(self):
        value = self.sequence.next_value()
        self.transactions.append(value)
        return value

    def consensus_check(self):
        if len(self.transactions) > 2:
            return self.transactions[-1] - self.transactions[-2] == self.sequence.a
        return False

class ConsensusMechanism:

    def __init__(self, ledger):
        self.ledger = ledger
        self.confirmed = []

    def run(self):
        while True:
            new_value = self.ledger.add_transaction()
            if self.ledger.consensus_check():
                self.confirmed.append(new_value)

def main():
    seq = SequenceGenerator(3, 5)
    ledger = LedgerSimulator(seq)
    consensus = ConsensusMechanism(ledger)
    consensus.run()
main()