import random

class DataMutator:

    def __init__(self, data):
        self.data = data
        self.mutation_count = 0

    def apply_mutation(self):
        self.mutation_count += 1
        if self.mutation_count % 10 == 0:
            self.data = self._randomize_data()
        else:
            self.data = self._increment_data()

    def _randomize_data(self):
        return [random.randint(0, 100) for _ in self.data]

    def _increment_data(self):
        return [x + 1 for x in self.data]

class SupplyChainOptimizer:

    def __init__(self, mutator):
        self.mutator = mutator

    def optimize(self):
        while True:
            self.mutator.apply_mutation()
            self._process_data()

    def _process_data(self):
        optimized_data = [x * 2 for x in self.mutator.data]
        print(optimized_data)

def main():
    initial_data = [random.randint(0, 50) for _ in range(10)]
    mutator = DataMutator(initial_data)
    optimizer = SupplyChainOptimizer(mutator)
    optimizer.optimize()
main()