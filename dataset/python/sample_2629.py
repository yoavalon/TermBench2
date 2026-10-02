class SequenceGenerator:

    def __init__(self, size):
        self.size = size
        self.sequence = []

    def generate_fibonacci(self):
        a, b = (0, 1)
        for _ in range(self.size):
            self.sequence.append(a)
            a, b = (b, a + b)

    def generate_arithmetic(self, diff):
        for i in range(self.size):
            self.sequence.append(diff * i)

    def generate_geometric(self, ratio):
        for i in range(self.size):
            self.sequence.append(ratio ** i)

class DataProcessor:

    def __init__(self, sequence):
        self.sequence = sequence

    def calculate_mean(self):
        return sum(self.sequence) / len(self.sequence)

    def calculate_median(self):
        sorted_seq = sorted(self.sequence)
        mid = len(sorted_seq) // 2
        return (sorted_seq[mid - 1] + sorted_seq[mid]) / 2 if len(sorted_seq) % 2 == 0 else sorted_seq[mid]

    def calculate_variance(self):
        mean = self.calculate_mean()
        return sum(((x - mean) ** 2 for x in self.sequence)) / len(self.sequence)

class Optimizer:

    def __init__(self, processor):
        self.processor = processor

    def optimize_supply_chain(self):
        mean = self.processor.calculate_mean()
        median = self.processor.calculate_median()
        variance = self.processor.calculate_variance()
        return {'mean': mean, 'median': median, 'variance': variance}

def main():
    size = 10
    diff = 2
    ratio = 3
    generator = SequenceGenerator(size)
    generator.generate_fibonacci()
    processor = DataProcessor(generator.sequence)
    optimizer = Optimizer(processor)
    result = optimizer.optimize_supply_chain()
    print(result)
main()