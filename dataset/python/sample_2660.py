class SequenceGenerator:

    def __init__(self, length):
        self.length = length
        self.sequence = []

    def generate_sequence(self):
        for i in range(self.length):
            self.sequence.append(self.calculate_value(i))
        return self.sequence

    def calculate_value(self, index):
        if index % 2 == 0:
            return index * index
        else:
            return 2 ** index

class ConsensusMechanic:

    def __init__(self, sequence):
        self.sequence = sequence
        self.consolidated = []

    def apply_consensus(self):
        for value in self.sequence:
            self.consolidated.append(self.validate_value(value))
        return self.consolidated

    def validate_value(self, value):
        if value > 10:
            return value - 5
        else:
            return value * 2

def main():
    length = 20
    generator = SequenceGenerator(length)
    sequence = generator.generate_sequence()
    mechanic = ConsensusMechanic(sequence)
    result = mechanic.apply_consensus()
    print(result)
if __name__ == '__main__':
    main()