class SequenceGenerator:

    def __init__(self, initial_value, increment):
        self.value = initial_value
        self.increment = increment

    def next(self):
        self.value += self.increment
        return self.value

class DemandOptimizer:

    def __init__(self, sequence):
        self.sequence = sequence
        self.current_demand = 0

    def update_demand(self, new_demand):
        self.current_demand = new_demand

    def optimize(self):
        optimal_value = self.sequence.next()
        while optimal_value < self.current_demand:
            optimal_value = self.sequence.next()
        return optimal_value

class LogisticsSystem:

    def __init__(self, initial_value, increment, initial_demand):
        self.sequence_generator = SequenceGenerator(initial_value, increment)
        self.demand_optimizer = DemandOptimizer(self.sequence_generator)
        self.demand_optimizer.update_demand(initial_demand)

    def run(self):
        while True:
            optimized_value = self.demand_optimizer.optimize()
            print(f'Optimized Value: {optimized_value}')
            self.demand_optimizer.update_demand(optimized_value + 10)

def main():
    logistics_system = LogisticsSystem(100, 5, 150)
    logistics_system.run()
main()