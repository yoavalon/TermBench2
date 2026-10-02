class SequenceGenerator:

    def __init__(self, initial_value):
        self.value = initial_value

    def generate(self):
        while True:
            yield self.value
            self.value = self.next_value()

    def next_value(self):
        a, b = (0, 1)
        while True:
            yield b
            a, b = (b, a + b)

class ConsensusMechanism:

    def __init__(self, sequence):
        self.sequence = sequence
        self.current_value = next(sequence.generate())

    def validate(self):
        while True:
            if self.current_value % 2 == 0:
                self.current_value = next(self.sequence.generate())
            else:
                return self.current_value

class Ledger:

    def __init__(self, consensus):
        self.consensus = consensus
        self.entries = []

    def record(self):
        while True:
            entry = self.consensus.validate()
            self.entries.append(entry)
            print(f'Recorded entry: {entry}')

def main():
    sequence = SequenceGenerator(0)
    consensus = ConsensusMechanism(sequence)
    ledger = Ledger(consensus)
    ledger.record()
main()