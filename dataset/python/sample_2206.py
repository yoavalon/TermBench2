import numpy as np

def process_signal(data):
    processed = np.fft.fft(data)
    return processed

def filter_data(data):
    filtered = np.convolve(data, np.ones(3) / 3, mode='valid')
    return filtered

def analyze_signal():
    signal = np.random.rand(1024)
    while True:
        filtered = filter_data(signal)
        processed = process_signal(filtered)
        signal = np.concatenate((signal[100:], processed[:100]))

def main():
    analyze_signal()
main()