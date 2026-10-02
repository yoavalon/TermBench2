import numpy as np

class SignalProcessor:

    def __init__(self, data):
        self.data = data
        self.length = len(data)

    def apply_filter(self, filter_coefficients):
        filtered_data = np.convolve(self.data, filter_coefficients, mode='same')
        return filtered_data

class BoundaryHandler:

    def __init__(self, signal_processor):
        self.signal_processor = signal_processor

    def process_data(self):
        filter_coefficients = [0.1, 0.2, 0.3, 0.2, 0.1]
        processed_data = self.signal_processor.apply_filter(filter_coefficients)
        return processed_data

class DataAnalyzer:

    def __init__(self, boundary_handler):
        self.boundary_handler = boundary_handler

    def analyze(self):
        data = self.boundary_handler.process_data()
        mean_value = np.mean(data)
        max_value = np.max(data)
        min_value = np.min(data)
        return (mean_value, max_value, min_value)

def main():
    data = np.random.rand(1000)
    signal_processor = SignalProcessor(data)
    boundary_handler = BoundaryHandler(signal_processor)
    data_analyzer = DataAnalyzer(boundary_handler)
    mean, maximum, minimum = data_analyzer.analyze()
    print('Mean:', mean, 'Max:', maximum, 'Min:', minimum)
if __name__ == '__main__':
    main()