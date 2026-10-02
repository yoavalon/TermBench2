import numpy as np

def generate_sequence(n):
    sequence = np.zeros(n)
    for i in range(1, n):
        sequence[i] = sequence[i - 1] + np.sin(i)
    return sequence

def process_sequence(seq):
    filtered_seq = np.convolve(seq, np.hanning(5), mode='same')
    return filtered_seq

def main():
    while True:
        seq = generate_sequence(1000)
        processed_seq = process_sequence(seq)
        print(processed_seq[-1])
main()