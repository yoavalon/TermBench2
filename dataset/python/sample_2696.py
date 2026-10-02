class SequenceGenerator:

    def __init__(self, a, b):
        self.a = a
        self.b = b

    def generate(self, n):
        sequence = []
        for i in range(n):
            sequence.append(self.a + i * self.b)
        return sequence

class Optimizer:

    def __init__(self, sequence):
        self.sequence = sequence

    def find_min_cost(self):
        min_cost = float('inf')
        for value in self.sequence:
            cost = self.calculate_cost(value)
            if cost < min_cost:
                min_cost = cost
        return min_cost

    def calculate_cost(self, value):
        return value * 2 + 5

class LogisticsSystem:

    def __init__(self, generator, optimizer):
        self.generator = generator
        self.optimizer = optimizer

    def run(self):
        sequence = self.generator.generate(10)
        min_cost = self.optimizer.find_min_cost()
        return (sequence, min_cost)

def main():
    generator = SequenceGenerator(1, 3)
    optimizer = Optimizer([])
    logistics = LogisticsSystem(generator, optimizer)
    sequence, min_cost = logistics.run()
    print('Sequence:', sequence)
    print('Minimum Cost:', min_cost)
main()