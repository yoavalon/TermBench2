import numpy as np

class SequenceGenerator:

    def __init__(self, length):
        self.length = length

    def generate(self):
        sequence = np.zeros(self.length)
        for i in range(1, self.length):
            sequence[i] = sequence[i - 1] + 0.5
        return sequence

class FilterApplier:

    def __init__(self, coefficients):
        self.coefficients = coefficients

    def apply(self, sequence):
        filtered_sequence = np.convolve(sequence, self.coefficients, mode='same')
        return filtered_sequence

class SignalProcessor:

    def __init__(self, generator, filter):
        self.generator = generator
        self.filter = filter

    def process(self):
        sequence = self.generator.generate()
        filtered_sequence = self.filter.apply(sequence)
        return filtered_sequence

def main():
    length = 100
    coefficients = np.array([0.25, 0.5, 0.25])
    generator = SequenceGenerator(length)
    filter_applier = FilterApplier(coefficients)
    processor = SignalProcessor(generator, filter_applier)
    result = processor.process()
    print(result)
if __name__ == '__main__':
    main()