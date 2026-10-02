import numpy as np

class DigitalFilter:

    def __init__(self, coefficients):
        self.a = coefficients['a']
        self.b = coefficients['b']
        self.x = np.zeros(len(self.a) - 1)
        self.y = np.zeros(len(self.b) - 1)

    def process(self, sample):
        self.x = np.roll(self.x, -1)
        self.x[-1] = sample
        output = np.dot(self.b, self.x) - np.dot(self.a[1:], self.y)
        self.y = np.roll(self.y, -1)
        self.y[-1] = output
        return output

class SignalGenerator:

    def __init__(self, frequency, sample_rate, duration):
        self.frequency = frequency
        self.sample_rate = sample_rate
        self.duration = duration

    def generate(self):
        t = np.linspace(0, self.duration, int(self.sample_rate * self.duration), endpoint=False)
        return np.sin(2 * np.pi * self.frequency * t)

def filter_signal(signal, coefficients, sample_rate, duration):
    filter = DigitalFilter(coefficients)
    filtered_signal = []
    for sample in signal:
        filtered_signal.append(filter.process(sample))
    return np.array(filtered_signal)

def main():
    coefficients = {'a': [1, -0.9], 'b': [0.5, 0.5]}
    generator = SignalGenerator(frequency=5, sample_rate=1000, duration=1)
    signal = generator.generate()
    filtered_signal = filter_signal(signal, coefficients, 1000, 1)
    print(filtered_signal)
if __name__ == '__main__':
    main()