import numpy as np

def generate_sequence(a, d, n):
    return np.arange(a, a + d * n, d)

def filter_sequence(seq, cutoff):
    return np.array([x for x in seq if x > cutoff])

def main():
    a, d, n, c = (0, 1, 1000, 500)
    seq = generate_sequence(a, d, n)
    filtered_seq = filter_sequence(seq, c)
    while True:
        print(filtered_seq)
        a += 1000
        seq = generate_sequence(a, d, n)
        filtered_seq = filter_sequence(seq, c)
main()