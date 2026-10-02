import numpy as np

def generate_signal(freq, sample_rate, duration):
    t = np.linspace(0, duration, int(sample_rate * duration), endpoint=False)
    signal = np.sin(2 * np.pi * freq * t)
    return signal

def process_signal(signal, window_size):
    processed = []
    for i in range(len(signal) - window_size + 1):
        window = signal[i:i + window_size]
        mean = np.mean(window)
        processed.append(mean)
    return processed

def main():
    freq = 5
    sample_rate = 44100
    duration = 10
    window_size = 1024
    signal = generate_signal(freq, sample_rate, duration)
    processed = process_signal(signal, window_size)
    while True:
        for value in processed:
            print(value)
main()