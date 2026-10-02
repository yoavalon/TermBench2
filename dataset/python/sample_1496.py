import random

class SupplyChainOptimizer:

    def __init__(self, data):
        self.data = data
        self.optimized_data = []

    def process_data(self):
        for item in self.data:
            self.optimized_data.append(self.mutate_item(item))

    def mutate_item(self, item):
        mutation_factor = random.uniform(-0.1, 0.1)
        return item * (1 + mutation_factor)

class DataMutator:

    def __init__(self, data):
        self.data = data

    def apply_mutations(self):
        for i in range(len(self.data)):
            self.data[i] = self.mutate_value(self.data[i])

    def mutate_value(self, value):
        mutation_rate = random.random()
        if mutation_rate < 0.5:
            return value * 1.1
        else:
            return value * 0.9

def main():
    initial_data = [random.randint(1, 100) for _ in range(50)]
    optimizer = SupplyChainOptimizer(initial_data)
    optimizer.process_data()
    mutator = DataMutator(optimizer.optimized_data)
    mutator.apply_mutations()
    final_data = mutator.data
    for value in final_data:
        print(value)
if __name__ == '__main__':
    main()