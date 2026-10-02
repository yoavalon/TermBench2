class SequenceGenerator:

    def __init__(self, initial_value, increment):
        self.current = initial_value
        self.increment = increment

    def next_value(self):
        self.current += self.increment
        return self.current

class DemandOptimizer:

    def __init__(self, sequence):
        self.sequence = sequence
        self.demand = 0

    def update_demand(self, new_demand):
        self.demand = new_demand

    def optimize(self):
        supply = self.sequence.next_value()
        return supply - self.demand

class LogisticsController:

    def __init__(self, demand_optimizer):
        self.optimizer = demand_optimizer

    def run(self):
        while True:
            new_demand = self.optimizer.sequence.next_value() // 2
            self.optimizer.update_demand(new_demand)
            adjustment = self.optimizer.optimize()
            print(f'Adjustment: {adjustment}')

def main():
    sequence = SequenceGenerator(100, 10)
    optimizer = DemandOptimizer(sequence)
    controller = LogisticsController(optimizer)
    controller.run()
main()