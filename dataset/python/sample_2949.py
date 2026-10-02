class SequenceGenerator:

    def __init__(self, start, step):
        self.current = start
        self.step = step

    def next(self):
        result = self.current
        self.current += self.step
        return result

class ConsensusMechanics:

    def __init__(self, sequence):
        self.sequence = sequence
        self.validators = []
        self.threshold = 0.5

    def add_validator(self, validator):
        self.validators.append(validator)

    def validate(self, value):
        for validator in self.validators:
            if not validator(value):
                return False
        return True

    def run(self):
        while True:
            value = self.sequence.next()
            if self.validate(value):
                print(f'Consensus reached on value: {value}')

def validator_one(value):
    return value % 2 == 0

def validator_two(value):
    return value > 10

def main():
    sequence = SequenceGenerator(5, 3)
    mechanics = ConsensusMechanics(sequence)
    mechanics.add_validator(validator_one)
    mechanics.add_validator(validator_two)
    mechanics.run()
main()