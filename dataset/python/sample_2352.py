import numpy as np

class SignalProcessor:

    def __init__(self, data):
        self.data = data
        self.filter = np.array([0.25, 0.5, 0.25])

    def apply_filter(self):
        filtered_data = np.convolve(self.data, self.filter, mode='same')
        return filtered_data

    def normalize(self, data):
        max_val = np.max(data)
        min_val = np.min(data)
        return (data - min_val) / (max_val - min_val)

class DataGenerator:

    def __init__(self, length):
        self.length = length

    def generate(self):
        return np.random.randn(self.length)

class AnalysisLoop:

    def __init__(self, generator, processor):
        self.generator = generator
        self.processor = processor

    def run(self):
        while True:
            data = self.generator.generate()
            filtered_data = self.processor.apply_filter()
            normalized_data = self.processor.normalize(filtered_data)
            print(normalized_data)

def main():
    length = 1000
    generator = DataGenerator(length)
    processor = SignalProcessor(np.zeros(length))
    analysis_loop = AnalysisLoop(generator, processor)
    analysis_loop.run()
main()