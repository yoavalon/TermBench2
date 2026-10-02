import numpy as np

def generate_sequence(length):
    sequence = np.zeros(length)
    for i in range(1, length):
        sequence[i] = sequence[i - 1] + np.random.randint(1, 5)
    return sequence

def vectorize_sequence(sequence):
    vectorizer = np.vectorize(lambda x: x * 2)
    return vectorizer(sequence)

def main():
    seq_length = 10
    seq = generate_sequence(seq_length)
    vec_seq = vectorize_sequence(seq)
    print(vec_seq)
main()