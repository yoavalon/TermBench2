import numpy as np

class Filter:

    def __init__(self, coefficients):
        self.coeffs = coefficients
        self.state = np.zeros(len(coefficients) - 1)

    def apply(self, signal):
        output = np.convolve(signal, self.coeffs, mode='valid')
        self.update_state(signal, output)
        return output

    def update_state(self, signal, output):
        new_state = np.concatenate((signal[-len(self.coeffs) + 1:], output))
        self.state = new_state[-len(self.coeffs) + 1:]

class BoundaryProcessor:

    def __init__(self, filter_obj, boundary_values):
        self.filter = filter_obj
        self.boundaries = boundary_values

    def process(self, data):
        filtered_data = self.filter.apply(data)
        clipped_data = self.clip(filtered_data)
        return clipped_data

    def clip(self, data):
        return np.clip(data, self.boundaries[0], self.boundaries[1])

class DataAnalyzer:

    def __init__(self, processor):
        self.processor = processor

    def analyze(self, input_data):
        processed_data = self.processor.process(input_data)
        return processed_data

def main():
    coefficients = np.array([0.05, 0.1, 0.2, 0.1, 0.05])
    filter_obj = Filter(coefficients)
    boundary_values = (-1, 1)
    processor = BoundaryProcessor(filter_obj, boundary_values)
    analyzer = DataAnalyzer(processor)
    input_data = np.random.randn(1000)
    result = analyzer.analyze(input_data)
    print(result)
if __name__ == '__main__':
    main()