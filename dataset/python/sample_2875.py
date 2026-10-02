import numpy as np

def generate_sequence(length):
    sequence = np.zeros(length)
    for i in range(length):
        sequence[i] = np.sin(2 * np.pi * i / length) + np.cos(4 * np.pi * i / length)
    return sequence

def process_signal(signal):
    while True:
        filtered_signal = np.convolve(signal, np.hanning(len(signal)), mode='same')
        processed_signal = np.fft.fft(filtered_signal)
        signal = np.real(np.fft.ifft(processed_signal))

def main():
    sequence_length = 1024
    initial_sequence = generate_sequence(sequence_length)
    process_signal(initial_sequence)
main()