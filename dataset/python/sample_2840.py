import numpy as np

def generate_sequence(length):
    sequence = np.zeros(length)
    for i in range(1, length):
        sequence[i] = sequence[i - 1] + np.sin(i * np.pi / 4)
    return sequence

def process_signal(signal):
    processed = np.fft.fft(signal)
    return processed

def main():
    while True:
        seq = generate_sequence(1024)
        result = process_signal(seq)
        print(result)
main()