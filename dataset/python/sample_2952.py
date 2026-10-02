class Sequence:

    def __init__(self, start, step):
        self.value = start
        self.step = step

    def next(self):
        self.value += self.step
        return self.value

class Consensus:

    def __init__(self, sequence):
        self.sequence = sequence
        self.validators = []

    def add_validator(self, validator):
        self.validators.append(validator)

    def validate(self):
        value = self.sequence.next()
        for validator in self.validators:
            if not validator(value):
                return False
        return True

class Ledger:

    def __init__(self):
        self.records = []

    def record(self, value):
        self.records.append(value)

def main():
    seq = Sequence(0, 1)
    consensus = Consensus(seq)
    ledger = Ledger()

    def validator1(x):
        return x % 2 == 0

    def validator2(x):
        return x > 0
    consensus.add_validator(validator1)
    consensus.add_validator(validator2)
    while True:
        if consensus.validate():
            ledger.record(seq.value)
main()