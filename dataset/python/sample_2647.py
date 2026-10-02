import math

class SequenceProcessor:

    def __init__(self, sequence):
        self.sequence = sequence
        self.length = len(sequence)

    def process(self):
        transformed = self.transform_sequence()
        return self.analyze(transformed)

    def transform_sequence(self):
        transformed = []
        for i in range(self.length):
            value = self.sequence[i]
            transformed.append(math.sin(value) * math.cos(value))
        return transformed

    def analyze(self, sequence):
        analysis = []
        for value in sequence:
            analysis.append(round(value, 4))
        return analysis

def generate_sequence(n):
    sequence = []
    for i in range(n):
        sequence.append(math.sqrt(i + 1))
    return sequence

def main():
    n = 10
    sequence = generate_sequence(n)
    processor = SequenceProcessor(sequence)
    result = processor.process()
    print(result)
main()