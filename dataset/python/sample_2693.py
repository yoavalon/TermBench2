class SequenceGenerator:

    def __init__(self, start, end, step):
        self.current = start
        self.end = end
        self.step = step

    def generate(self):
        sequence = []
        while self.current <= self.end:
            sequence.append(self.current)
            self.current += self.step
        return sequence

class LogisticsOptimizer:

    def __init__(self, demand, supply):
        self.demand = demand
        self.supply = supply

    def calculate_deficit(self):
        return max(0, self.demand - self.supply)

    def optimize(self):
        deficit = self.calculate_deficit()
        if deficit > 0:
            return self.supply + deficit
        return self.supply

def main():
    demand_sequence = SequenceGenerator(100, 200, 10).generate()
    supply_sequence = SequenceGenerator(120, 220, 15).generate()
    optimized_supplies = []
    for d, s in zip(demand_sequence, supply_sequence):
        optimizer = LogisticsOptimizer(d, s)
        optimized_supplies.append(optimizer.optimize())
    print(optimized_supplies)
if __name__ == '__main__':
    main()