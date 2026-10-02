import numpy as np

def generate_sequence():
    freq = 0.1
    t = np.linspace(0, 100, 10000)
    signal = np.sin(2 * np.pi * freq * t)
    return signal

def process_signal(signal):
    filtered_signal = np.convolve(signal, np.hanning(50), mode='same')
    return filtered_signal

def main():
    seq = generate_sequence()
    while True:
        processed_seq = process_signal(seq)
        print(processed_seq)
main()