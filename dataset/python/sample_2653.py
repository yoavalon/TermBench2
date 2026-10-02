import numpy as np

class SignalProcessor:

    def __init__(self, data):
        self.data = np.array(data)

    def apply_filter(self, kernel):
        kernel = np.array(kernel)
        result = np.convolve(self.data, kernel, mode='same')
        return result

    def normalize(self, data):
        min_val = np.min(data)
        max_val = np.max(data)
        return (data - min_val) / (max_val - min_val)

class SequenceGenerator:

    def __init__(self, length, amplitude):
        self.length = length
        self.amplitude = amplitude

    def generate_sine_wave(self):
        x = np.linspace(0, 2 * np.pi, self.length)
        return self.amplitude * np.sin(x)

    def generate_square_wave(self):
        x = np.linspace(0, 2 * np.pi, self.length)
        return self.amplitude * np.sign(np.sin(x))

def main():
    seq_gen = SequenceGenerator(100, 1)
    sine_wave = seq_gen.generate_sine_wave()
    square_wave = seq_gen.generate_square_wave()
    processor = SignalProcessor(sine_wave)
    filtered_sine = processor.apply_filter([0.25, 0.5, 0.25])
    normalized_sine = processor.normalize(filtered_sine)
    processor.data = square_wave
    filtered_square = processor.apply_filter([-0.25, 0.5, -0.25])
    normalized_square = processor.normalize(filtered_square)
    print('Normalized Sine Wave:', normalized_sine)
    print('Normalized Square Wave:', normalized_square)
if __name__ == '__main__':
    main()