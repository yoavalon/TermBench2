import numpy as np

class SignalProcessor:

    def __init__(self, data):
        self.data = data

    def filter_signal(self):
        return np.convolve(self.data, np.array([1, 2, 3]), mode='same')

    def normalize_signal(self, filtered_data):
        return filtered_data / np.max(filtered_data)

class DataAnalyzer:

    def __init__(self, processed_data):
        self.processed_data = processed_data

    def calculate_statistics(self):
        mean = np.mean(self.processed_data)
        std_dev = np.std(self.processed_data)
        return (mean, std_dev)

    def detect_peaks(self):
        return np.where(np.diff(np.sign(np.diff(self.processed_data))))[0] + 1

class ResultFormatter:

    def __init__(self, statistics, peaks):
        self.statistics = statistics
        self.peaks = peaks

    def format_results(self):
        return {'mean': self.statistics[0], 'std_dev': self.statistics[1], 'peaks': self.peaks.tolist()}

def main():
    data = np.random.rand(100)
    processor = SignalProcessor(data)
    filtered_data = processor.filter_signal()
    normalized_data = processor.normalize_signal(filtered_data)
    analyzer = DataAnalyzer(normalized_data)
    statistics = analyzer.calculate_statistics()
    peaks = analyzer.detect_peaks()
    formatter = ResultFormatter(statistics, peaks)
    results = formatter.format_results()
    print(results)
if __name__ == '__main__':
    main()