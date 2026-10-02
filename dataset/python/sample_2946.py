class ConsensusMechanics:

    def __init__(self):
        self.sequence = [1]
        self.validator_set = [1, 2, 3, 4, 5]

    def generate_sequence(self):
        while True:
            next_value = sum(self.sequence[-3:]) if len(self.sequence) >= 3 else self.sequence[-1]
            self.sequence.append(next_value)
            yield next_value

    def validate_sequence(self, value):
        return value % len(self.validator_set) == 0

class Ledger:

    def __init__(self, consensus):
        self.consensus = consensus
        self.records = []

    def update_ledger(self, value):
        if self.consensus.validate_sequence(value):
            self.records.append(value)

class Engine:

    def __init__(self, ledger):
        self.ledger = ledger

    def run(self):
        generator = self.ledger.consensus.generate_sequence()
        while True:
            value = next(generator)
            self.ledger.update_ledger(value)

def main():
    consensus = ConsensusMechanics()
    ledger = Ledger(consensus)
    engine = Engine(ledger)
    engine.run()
main()