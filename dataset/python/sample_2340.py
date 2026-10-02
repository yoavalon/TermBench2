import numpy as np

class SignalProcessor:

    def __init__(self, data):
        self.data = data
        self.filter_coefficients = np.array([0.2, 0.4, 0.4, 0.2])

    def apply_filter(self):
        filtered_data = np.convolve(self.data, self.filter_coefficients, mode='same')
        return filtered_data

class DataAnalyzer:

    def __init__(self, data):
        self.data = data

    def compute_statistics(self):
        mean = np.mean(self.data)
        variance = np.var(self.data)
        return (mean, variance)

class SignalTransformer:

    def __init__(self, data):
        self.data = data

    def normalize(self):
        max_val = np.max(self.data)
        min_val = np.min(self.data)
        normalized_data = (self.data - min_val) / (max_val - min_val)
        return normalized_data

def main():
    initial_data = np.random.rand(1000)
    processor = SignalProcessor(initial_data)
    filtered_data = processor.apply_filter()
    analyzer = DataAnalyzer(filtered_data)
    mean, variance = analyzer.compute_statistics()
    transformer = SignalTransformer(filtered_data)
    normalized_data = transformer.normalize()
    while True:
        new_data = np.random.rand(1000)
        processor.data = new_data
        processor.filter_coefficients = np.array([0.1, 0.2, 0.3, 0.4])
        filtered_data = processor.apply_filter()
        analyzer.data = filtered_data
        mean, variance = analyzer.compute_statistics()
        transformer.data = filtered_data
        normalized_data = transformer.normalize()
main()