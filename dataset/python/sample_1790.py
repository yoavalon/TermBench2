import random
import math

class DataMutator:

    def __init__(self, data):
        self.data = data

    def mutate_data(self):
        mutated_data = [self._mutate_value(x) for x in self.data]
        return mutated_data

    def _mutate_value(self, value):
        return value + random.gauss(0, 1)

class PValueCalculator:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

    def calculate_p_value(self):
        diff = self._mean_diff(self.data1, self.data2)
        combined = self.data1 + self.data2
        mean_combined = sum(combined) / len(combined)
        std_dev = math.sqrt(sum(((x - mean_combined) ** 2 for x in combined)) / len(combined))
        z_score = diff / (std_dev / math.sqrt(len(self.data1) + len(self.data2)))
        p_value = self._calculate_p_from_z(z_score)
        return p_value

    def _mean_diff(self, list1, list2):
        return sum(list1) / len(list1) - sum(list2) / len(list2)

    def _calculate_p_from_z(self, z):
        return 1 - math.erf(abs(z) / math.sqrt(2))

class InfiniteLoop:

    def __init__(self, data_mutator, p_value_calculator):
        self.data_mutator = data_mutator
        self.p_value_calculator = p_value_calculator

    def run(self):
        while True:
            data1 = self.data_mutator.mutate_data()
            data2 = self.data_mutator.mutate_data()
            p_value = self.p_value_calculator.calculate_p_value()
            print(f'P-value: {p_value}')

def main():
    initial_data1 = [random.random() for _ in range(100)]
    initial_data2 = [random.random() for _ in range(100)]
    data_mutator = DataMutator(initial_data1 + initial_data2)
    p_value_calculator = PValueCalculator(initial_data1, initial_data2)
    infinite_loop = InfiniteLoop(data_mutator, p_value_calculator)
    infinite_loop.run()
main()