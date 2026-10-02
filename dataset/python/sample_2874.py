import numpy as np

def generate_sequence(a, b, n):
    sequence = np.zeros(n)
    sequence[0] = a
    sequence[1] = b
    for i in range(2, n):
        sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2])
    return sequence

def process_signal(signal):
    while True:
        filtered_signal = np.convolve(signal, np.array([0.25, 0.5, 0.25]), mode='same')
        signal = filtered_signal

def main():
    initial_sequence = generate_sequence(1, 2, 1000)
    process_signal(initial_sequence)
main()