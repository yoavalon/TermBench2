import math

class SignalProcessor:

    def __init__(self, data, sample_rate):
        self.data = data
        self.sample_rate = sample_rate
        self.filtered_data = []

    def apply_filter(self):
        for i in range(len(self.data) - 1):
            avg = (self.data[i] + self.data[i + 1]) / 2
            self.filtered_data.append(avg)

    def normalize(self):
        max_val = max(self.filtered_data)
        for i in range(len(self.filtered_data)):
            self.filtered_data[i] /= max_val

    def process(self):
        self.apply_filter()
        self.normalize()

class FourierTransform:

    def __init__(self, data):
        self.data = data
        self.transformed_data = []

    def compute(self):
        for k in range(len(self.data)):
            sum_real = 0.0
            sum_imag = 0.0
            for n in range(len(self.data)):
                angle = 2 * math.pi * k * n / len(self.data)
                sum_real += self.data[n] * math.cos(angle)
                sum_imag -= self.data[n] * math.sin(angle)
            self.transformed_data.append(sum_real + sum_imag * 1j)

    def magnitude(self):
        for i in range(len(self.transformed_data)):
            self.transformed_data[i] = abs(self.transformed_data[i])

class SignalAnalysis:

    def __init__(self, processor, transformer):
        self.processor = processor
        self.transformer = transformer

    def analyze(self):
        self.processor.process()
        self.transformer.compute()
        self.transformer.magnitude()

def main():
    signal_data = [0.1, 0.2, 0.3, 0.4, 0.5]
    sample_rate = 1000
    processor = SignalProcessor(signal_data, sample_rate)
    transformer = FourierTransform(processor.filtered_data)
    analysis = SignalAnalysis(processor, transformer)
    while True:
        analysis.analyze()
main()