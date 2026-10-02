import numpy as np

class SequenceGenerator:

    def __init__(self, length):
        self.length = length
        self.data = np.zeros(length)

    def generate_fibonacci(self):
        if self.length > 0:
            self.data[0] = 0
        if self.length > 1:
            self.data[1] = 1
        for i in range(2, self.length):
            self.data[i] = self.data[i - 1] + self.data[i - 2]

    def generate_harmonic(self):
        for i in range(self.length):
            self.data[i] = 1 / (i + 1)

    def get_sequence(self):
        return self.data

def process_sequence(seq):
    filtered_seq = np.where(seq > 0.5, seq, 0)
    return filtered_seq

def analyze_sequence(seq):
    mean_value = np.mean(seq)
    max_value = np.max(seq)
    min_value = np.min(seq)
    return (mean_value, max_value, min_value)

def main():
    seq_gen = SequenceGenerator(10)
    seq_gen.generate_fibonacci()
    seq = seq_gen.get_sequence()
    processed_seq = process_sequence(seq)
    mean, max_val, min_val = analyze_sequence(processed_seq)
    print('Mean:', mean, 'Max:', max_val, 'Min:', min_val)
main()