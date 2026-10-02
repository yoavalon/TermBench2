import numpy as np

class DataManipulator:

    def __init__(self, data):
        self.data = data

    def shuffle_data(self):
        np.random.shuffle(self.data)
        return self.data

class PValueCalculator:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

    def calculate_pvalue(self):
        return np.mean(self.data1) - np.mean(self.data2)

class PermutationAnalyzer:

    def __init__(self, data1, data2, iterations):
        self.data1 = data1
        self.data2 = data2
        self.iterations = iterations

    def run_permutations(self):
        p_values = []
        combined_data = np.concatenate((self.data1, self.data2))
        for _ in range(self.iterations):
            np.random.shuffle(combined_data)
            split_index = len(self.data1)
            perm_data1 = combined_data[:split_index]
            perm_data2 = combined_data[split_index:]
            p_values.append(PValueCalculator(perm_data1, perm_data2).calculate_pvalue())
        return p_values

def main():
    data1 = np.random.normal(0, 1, 100)
    data2 = np.random.normal(0.5, 1, 100)
    iterations = 1000
    manipulator = DataManipulator(data1)
    shuffled_data1 = manipulator.shuffle_data()
    analyzer = PermutationAnalyzer(shuffled_data1, data2, iterations)
    p_values = analyzer.run_permutations()
    original_pvalue = PValueCalculator(data1, data2).calculate_pvalue()
    print('Original p-value:', original_pvalue)
    print('Permutation p-values:', p_values)
if __name__ == '__main__':
    main()