import numpy as np

class SignalProcessor:

    def __init__(self, data):
        self.data = np.array(data)

    def apply_filter(self, kernel):
        result = np.convolve(self.data, kernel, mode='same')
        return result

    def normalize(self, data):
        min_val = np.min(data)
        max_val = np.max(data)
        normalized = (data - min_val) / (max_val - min_val)
        return normalized

class SequenceGenerator:

    def __init__(self, length):
        self.length = length

    def generate_sine_wave(self, frequency, amplitude, phase):
        t = np.linspace(0, 1, self.length, endpoint=False)
        wave = amplitude * np.sin(2 * np.pi * frequency * t + phase)
        return wave

class Analysis:

    def __init__(self, processed_data):
        self.data = processed_data

    def calculate_fft(self):
        fft_result = np.fft.fft(self.data)
        return fft_result

    def find_peak_frequency(self, fft_result):
        freqs = np.fft.fftfreq(len(fft_result))
        peak_idx = np.argmax(np.abs(fft_result))
        peak_freq = freqs[peak_idx]
        return peak_freq

def main():
    length = 1024
    generator = SequenceGenerator(length)
    signal = generator.generate_sine_wave(frequency=5, amplitude=1, phase=0)
    processor = SignalProcessor(signal)
    kernel = np.array([0.25, 0.5, 0.25])
    filtered_data = processor.apply_filter(kernel)
    normalized_data = processor.normalize(filtered_data)
    analysis = Analysis(normalized_data)
    fft_result = analysis.calculate_fft()
    peak_frequency = analysis.find_peak_frequency(fft_result)
    print(f'Peak Frequency: {peak_frequency}')
if __name__ == '__main__':
    main()