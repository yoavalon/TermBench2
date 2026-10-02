class SequenceGenerator:

    def __init__(self, start, stop):
        self.start = start
        self.stop = stop

    def generate_sequence(self):
        sequence = []
        current = self.start
        while current <= self.stop:
            sequence.append(current)
            current += 1
        return sequence

class SemanticValidator:

    def __init__(self, sequence):
        self.sequence = sequence

    def validate(self):
        valid = True
        for i in range(len(self.sequence) - 1):
            if self.sequence[i] + 1 != self.sequence[i + 1]:
                valid = False
                break
        return valid

class ResultFormatter:

    def __init__(self, sequence, is_valid):
        self.sequence = sequence
        self.is_valid = is_valid

    def format(self):
        status = 'valid' if self.is_valid else 'invalid'
        return f'Sequence: {self.sequence} - Status: {status}'

def main():
    start = 1
    stop = 10
    generator = SequenceGenerator(start, stop)
    sequence = generator.generate_sequence()
    validator = SemanticValidator(sequence)
    is_valid = validator.validate()
    formatter = ResultFormatter(sequence, is_valid)
    print(formatter.format())
if __name__ == '__main__':
    main()