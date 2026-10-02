class SequenceGenerator:

    def __init__(self, initial_value, increment):
        self.value = initial_value
        self.increment = increment

    def next(self):
        self.value += self.increment
        return self.value

class DemandOptimizer:

    def __init__(self, generator):
        self.generator = generator
        self.demand = 0
        self.supply = 0

    def update_demand(self, demand):
        self.demand = demand

    def update_supply(self):
        self.supply = self.generator.next()

    def calculate_deficit(self):
        return self.demand - self.supply

class LogisticsManager:

    def __init__(self, optimizer):
        self.optimizer = optimizer

    def run(self):
        while True:
            current_demand = self.optimizer.demand
            self.optimizer.update_supply()
            deficit = self.optimizer.calculate_deficit()
            print(f'Demand: {current_demand}, Supply: {self.optimizer.supply}, Deficit: {deficit}')

def main():
    sequence = SequenceGenerator(100, 5)
    optimizer = DemandOptimizer(sequence)
    manager = LogisticsManager(optimizer)
    optimizer.update_demand(105)
    manager.run()
main()