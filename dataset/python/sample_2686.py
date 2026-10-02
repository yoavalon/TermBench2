import numpy as np
import random

class SequenceGenerator:

    def __init__(self, size):
        self.size = size
        self.data = np.random.rand(size)

    def generate_sequence(self):
        return self.data

class PValueCalculator:

    def __init__(self, sequence1, sequence2):
        self.sequence1 = sequence1
        self.sequence2 = sequence2

    def calculate_p_value(self):
        diff = np.mean(self.sequence1) - np.mean(self.sequence2)
        bootstrap_samples = []
        for _ in range(1000):
            combined = np.concatenate([self.sequence1, self.sequence2])
            random.shuffle(combined)
            new_mean_diff = np.mean(combined[:len(self.sequence1)]) - np.mean(combined[len(self.sequence1):])
            bootstrap_samples.append(new_mean_diff)
        bootstrap_samples = np.array(bootstrap_samples)
        p_value = (np.sum(np.abs(bootstrap_samples) >= np.abs(diff)) + 1) / (len(bootstrap_samples) + 1)
        return p_value

class AnalysisRunner:

    def __init__(self, sequence_generator1, sequence_generator2):
        self.sequence_generator1 = sequence_generator1
        self.sequence_generator2 = sequence_generator2

    def run_analysis(self):
        seq1 = self.sequence_generator1.generate_sequence()
        seq2 = self.sequence_generator2.generate_sequence()
        p_value_calculator = PValueCalculator(seq1, seq2)
        p_value = p_value_calculator.calculate_p_value()
        return p_value

def main():
    size1, size2 = (100, 100)
    seq_gen1 = SequenceGenerator(size1)
    seq_gen2 = SequenceGenerator(size2)
    analysis_runner = AnalysisRunner(seq_gen1, seq_gen2)
    result = analysis_runner.run_analysis()
    print(result)
if __name__ == '__main__':
    main()