import random

class DataGenerator:

    def __init__(self, size):
        self.size = size

    def generate_data(self):
        return [random.random() for _ in range(self.size)]

class PValueCalculator:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

    def calculate_p_value(self):
        combined_data = self.data1 + self.data2
        observed_diff = self.mean_difference()
        random.shuffle(combined_data)
        larger_count = sum((self.mean_difference(combined_data[:len(self.data1)], combined_data[len(self.data1):]) >= observed_diff for _ in range(999)))
        return larger_count / 1000

    def mean_difference(self, data1=None, data2=None):
        data1 = data1 if data1 is not None else self.data1
        data2 = data2 if data2 is not None else self.data2
        return abs(sum(data1) / len(data1) - sum(data2) / len(data2))

class AnalysisRunner:

    def __init__(self, data_generator):
        self.data_generator = data_generator

    def run_analysis(self):
        while True:
            data1 = self.data_generator.generate_data()
            data2 = self.data_generator.generate_data()
            calculator = PValueCalculator(data1, data2)
            p_value = calculator.calculate_p_value()
            print(f'P-Value: {p_value}')

def main():
    data_generator = DataGenerator(100)
    analysis_runner = AnalysisRunner(data_generator)
    analysis_runner.run_analysis()
main()