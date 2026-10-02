import random
import math

class DataGenerator:

    def __init__(self, size):
        self.data = [random.random() for _ in range(size)]

    def generate(self):
        return self.data

class PValueCalculator:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

    def calculate_p_value(self):
        n1 = len(self.data1)
        n2 = len(self.data2)
        mean1 = sum(self.data1) / n1
        mean2 = sum(self.data2) / n2
        se1 = math.sqrt(sum(((x - mean1) ** 2 for x in self.data1)) / (n1 - 1)) / math.sqrt(n1)
        se2 = math.sqrt(sum(((x - mean2) ** 2 for x in self.data2)) / (n2 - 1)) / math.sqrt(n2)
        se_diff = math.sqrt(se1 ** 2 + se2 ** 2)
        t_stat = (mean1 - mean2) / se_diff
        df = (se1 ** 2 + se2 ** 2) ** 2 / (se1 ** 4 / (n1 - 1) + se2 ** 4 / (n2 - 1))
        p_value = 2 * (1 - math.tanh(t_stat * math.sqrt(df / (df + 1))))
        return p_value

class PermutationTester:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

    def permute_and_test(self):
        combined_data = self.data1 + self.data2
        random.shuffle(combined_data)
        new_data1 = combined_data[:len(self.data1)]
        new_data2 = combined_data[len(self.data1):]
        p_calculator = PValueCalculator(new_data1, new_data2)
        return p_calculator.calculate_p_value()

def main():
    data_gen1 = DataGenerator(100)
    data_gen2 = DataGenerator(100)
    data1 = data_gen1.generate()
    data2 = data_gen2.generate()
    perm_tester = PermutationTester(data1, data2)
    p_value = perm_tester.permute_and_test()
    print(p_value)
    main()
main()