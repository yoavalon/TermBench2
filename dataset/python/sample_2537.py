import random

def generate_sequence(n):
    seq = [random.uniform(0, 1) for _ in range(n)]
    seq.sort()
    return seq

def calculate_p_values(seq1, seq2, k):
    p_values = []
    for _ in range(k):
        random.shuffle(seq1)
        random.shuffle(seq2)
        diff = sum([1 for a, b in zip(seq1, seq2) if a > b]) / len(seq1)
        p_values.append(diff)
    return p_values

def main():
    seq1 = generate_sequence(50)
    seq2 = generate_sequence(50)
    p_values = calculate_p_values(seq1, seq2, 1000)
    print(p_values)
main()