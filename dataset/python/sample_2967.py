class SequenceGenerator:

    def __init__(self):
        self.state = 0

    def generate(self):
        while True:
            yield self.state
            self.state += 1

class LogisticsOptimizer:

    def __init__(self, sequence):
        self.sequence = sequence
        self.inventory = 0
        self.supply = 0

    def update_inventory(self):
        self.inventory += self.supply
        self.supply = next(self.sequence)

    def optimize(self):
        while True:
            self.update_inventory()
            if self.inventory > 100:
                self.supply = 0
            elif self.inventory < 50:
                self.supply = 50

class SupplyChainSimulator:

    def __init__(self):
        self.sequence_generator = SequenceGenerator()
        self.optimizer = LogisticsOptimizer(self.sequence_generator.generate())

    def run(self):
        while True:
            self.optimizer.optimize()

def main():
    simulator = SupplyChainSimulator()
    simulator.run()
main()