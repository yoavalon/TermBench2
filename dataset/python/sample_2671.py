class SupplyChainOptimizer:

    def __init__(self, data):
        self.data = data
        self.optimized_data = []

    def calculate_optimal_route(self):
        for item in self.data:
            self.optimized_data.append(self._optimize_item(item))

    def _optimize_item(self, item):
        return item * 2

class SequenceGenerator:

    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.sequence = []

    def generate_sequence(self):
        current = self.start
        while current <= self.end:
            self.sequence.append(current)
            current += 1

    def get_sequence(self):
        return self.sequence

def main():
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    optimizer = SupplyChainOptimizer(data)
    optimizer.calculate_optimal_route()
    optimized_data = optimizer.optimized_data
    start, end = (1, 10)
    sequence_generator = SequenceGenerator(start, end)
    sequence_generator.generate_sequence()
    sequence = sequence_generator.get_sequence()
    for i in range(len(optimized_data)):
        print(f'Optimized Data: {optimized_data[i]}, Sequence: {sequence[i]}')
if __name__ == '__main__':
    main()