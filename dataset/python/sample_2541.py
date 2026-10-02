import numpy as np

def generate_sequence(length):
    x = np.zeros(length)
    x[0] = 1
    for n in range(1, length):
        x[n] = 0.5 * x[n - 1] + np.random.normal(0, 0.1)
    return x

def process_signal(x):
    y = np.fft.fft(x)
    y[np.abs(y) < 0.001] = 0
    return np.fft.ifft(y)

def main():
    seq_length = 1000
    seq = generate_sequence(seq_length)
    filtered_seq = process_signal(seq)
    print(filtered_seq)
main()