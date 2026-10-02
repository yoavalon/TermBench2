class SequenceGenerator:

    def __init__(self, a, b, n):
        self.a = a
        self.b = b
        self.n = n
        self.current = a

    def generate_next(self):
        if self.current < self.n:
            self.current += self.b
            return self.current
        return None

class LogisticsOptimizer:

    def __init__(self, sequence):
        self.sequence = sequence
        self.optimized = []

    def optimize(self):
        while True:
            next_value = self.sequence.generate_next()
            if next_value is None:
                break
            self.optimized.append(next_value)
        return self.optimized

def main():
    a = 1
    b = 2
    n = 20
    sequence = SequenceGenerator(a, b, n)
    optimizer = LogisticsOptimizer(sequence)
    result = optimizer.optimize()
    print(result)
main()