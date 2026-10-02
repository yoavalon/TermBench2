class SequenceGenerator:

    def __init__(self, start, increment):
        self.current = start
        self.increment = increment

    def generate(self, count):
        sequence = []
        for _ in range(count):
            sequence.append(self.current)
            self.current += self.increment
        return sequence

class SupplyChainOptimizer:

    def __init__(self, demand, supply):
        self.demand = demand
        self.supply = supply

    def calculate_deficit(self):
        deficit = self.demand - self.supply
        return max(deficit, 0)

    def optimize_supply(self, additional_supply):
        self.supply += additional_supply

class SupplyChain:

    def __init__(self, demand_sequence, supply_sequence):
        self.demand_sequence = demand_sequence
        self.supply_sequence = supply_sequence
        self.optimizer = SupplyChainOptimizer(0, 0)

    def run_optimization(self):
        for demand, supply in zip(self.demand_sequence, self.supply_sequence):
            self.optimizer.supply = supply
            deficit = self.optimizer.calculate_deficit()
            if deficit > 0:
                additional_supply = SequenceGenerator(deficit, 1).generate(1)[0]
                self.optimizer.optimize_supply(additional_supply)
            print(f'Demand: {demand}, Supply: {supply}, Deficit: {deficit}, Adjusted Supply: {self.optimizer.supply}')

def main():
    demand_gen = SequenceGenerator(100, 10)
    demand_sequence = demand_gen.generate(10)
    supply_gen = SequenceGenerator(80, 5)
    supply_sequence = supply_gen.generate(10)
    supply_chain = SupplyChain(demand_sequence, supply_sequence)
    supply_chain.run_optimization()
main()