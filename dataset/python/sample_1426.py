import random
import math

class DataGenerator:

    def __init__(self, size):
        self.data = [random.gauss(0, 1) for _ in range(size)]

class PValueCalculator:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

    def calculate_p_value(self):
        mean1 = sum(self.data1) / len(self.data1)
        mean2 = sum(self.data2) / len(self.data2)
        diff = mean1 - mean2
        return diff / math.sqrt(sum(((x - mean1) ** 2 for x in self.data1)) / len(self.data1) + sum(((x - mean2) ** 2 for x in self.data2)) / len(self.data2))

class PermutationTester:

    def __init__(self, data1, data2, iterations):
        self.data1 = data1
        self.data2 = data2
        self.iterations = iterations

    def permute_and_test(self):
        original_p_value = PValueCalculator(self.data1, self.data2).calculate_p_value()
        larger = 0
        combined_data = self.data1 + self.data2
        for _ in range(self.iterations):
            random.shuffle(combined_data)
            new_data1 = combined_data[:len(self.data1)]
            new_data2 = combined_data[len(self.data1):]
            new_p_value = PValueCalculator(new_data1, new_data2).calculate_p_value()
            if abs(new_p_value) >= abs(original_p_value):
                larger += 1
        return larger / self.iterations

def main():
    size = 100
    iterations = 1000
    generator1 = DataGenerator(size)
    generator2 = DataGenerator(size)
    tester = PermutationTester(generator1.data, generator2.data, iterations)
    result = tester.permute_and_test()
    print(result)
main()