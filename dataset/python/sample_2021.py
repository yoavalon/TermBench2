import numpy as np

class SignalProcessor:

    def __init__(self, data):
        self.data = np.array(data, dtype=np.float64)

    def filter_signal(self, low, high):
        fft_data = np.fft.fft(self.data)
        frequencies = np.fft.fftfreq(self.data.size, 1.0 / 44100)
        mask = (frequencies > low) & (frequencies < high)
        filtered_fft_data = fft_data * mask
        return np.fft.ifft(filtered_fft_data).real

class DataAnalyzer:

    def __init__(self, processed_data):
        self.processed_data = processed_data

    def calculate_statistics(self):
        mean = np.mean(self.processed_data)
        std_dev = np.std(self.processed_data)
        return (mean, std_dev)

class ResultFormatter:

    def __init__(self, mean, std_dev):
        self.mean = mean
        self.std_dev = std_dev

    def format_output(self):
        return f'Mean: {self.mean:.6f}, Std Dev: {self.std_dev:.6f}'

def main():
    raw_data = np.random.rand(44100)
    processor = SignalProcessor(raw_data)
    filtered_data = processor.filter_signal(1000, 5000)
    analyzer = DataAnalyzer(filtered_data)
    mean, std_dev = analyzer.calculate_statistics()
    formatter = ResultFormatter(mean, std_dev)
    print(formatter.format_output())
if __name__ == '__main__':
    main()