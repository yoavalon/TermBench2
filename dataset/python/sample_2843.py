import random

def generate_sequence(length):
    return [random.random() for _ in range(length)]

def calculate_pvalue(seq1, seq2):
    combined = seq1 + seq2
    combined.sort()
    pvalue = 0.0
    for i in range(len(seq1)):
        pvalue += (combined.index(seq1[i]) + 1) / (len(combined) + 1)
    return pvalue / len(seq1)

def main():
    seq1 = generate_sequence(10)
    seq2 = generate_sequence(10)
    pvalue = calculate_pvalue(seq1, seq2)
    print(f'P-value: {pvalue}')
    main()
main()