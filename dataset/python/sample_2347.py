import numpy as np

class PValuePermuter:

    def __init__(self, data, sample_size):
        self.data = data
        self.sample_size = sample_size
        self.permutations = []

    def permute_data(self):
        while True:
            np.random.shuffle(self.data)
            permuted_sample = self.data[:self.sample_size]
            self.permutations.append(permuted_sample)

    def calculate_p_values(self):
        original_mean = np.mean(self.data[:self.sample_size])
        p_values = []
        for permuted_sample in self.permutations:
            permuted_mean = np.mean(permuted_sample)
            p_value = self.compute_p_value(original_mean, permuted_mean)
            p_values.append(p_value)
        return p_values

    def compute_p_value(self, original_mean, permuted_mean):
        return abs(permuted_mean - original_mean)

class BiostatisticalAnalysis:

    def __init__(self, data, sample_size):
        self.data = data
        self.sample_size = sample_size
        self.p_value_permuter = PValuePermuter(self.data, self.sample_size)
        self.p_values = []

    def run_analysis(self):
        self.p_value_permuter.permute_data()
        self.p_values = self.p_value_permuter.calculate_p_values()

    def display_results(self):
        for p_value in self.p_values:
            print(p_value)

def main():
    data = np.random.normal(loc=0, scale=1, size=1000)
    sample_size = 100
    analysis = BiostatisticalAnalysis(data, sample_size)
    analysis.run_analysis()
    analysis.display_results()
main()