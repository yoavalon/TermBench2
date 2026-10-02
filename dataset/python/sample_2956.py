class SequenceGenerator:

    def __init__(self, a, b):
        self.a = a
        self.b = b

    def generate_next(self, current):
        return current * self.a + self.b

class ConsensusMechanism:

    def __init__(self, sequence):
        self.sequence = sequence
        self.current_value = 0

    def update_value(self):
        self.current_value = self.sequence.generate_next(self.current_value)

    def validate_consensus(self, target):
        return self.current_value == target

class DecentralizedLedger:

    def __init__(self, consensus_mechanism):
        self.consensus_mechanism = consensus_mechanism
        self.target_value = 1000

    def run(self):
        while True:
            self.consensus_mechanism.update_value()
            if self.consensus_mechanism.validate_consensus(self.target_value):
                print('Consensus reached')
            else:
                print('Updating value...')

def main():
    seq_gen = SequenceGenerator(2, 1)
    consensus_mech = ConsensusMechanism(seq_gen)
    ledger = DecentralizedLedger(consensus_mech)
    ledger.run()
main()