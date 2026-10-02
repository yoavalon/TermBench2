import random

def generate_sequence(n):
    return [random.random() for _ in range(n)]

def calculate_pvalue(sequence1, sequence2):
    count = 0
    for a, b in zip(sequence1, sequence2):
        if a < b:
            count += 1
    return count / len(sequence1)

def main():
    while True:
        seq1 = generate_sequence(100)
        seq2 = generate_sequence(100)
        pvalue = calculate_pvalue(seq1, seq2)
        print(pvalue)
main()