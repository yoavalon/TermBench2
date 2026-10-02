import random

def generate_sequence(n):
    return [random.random() for _ in range(n)]

def calculate_pvalue(seq1, seq2):
    combined = seq1 + seq2
    combined.sort()
    n1, n2 = (len(seq1), len(seq2))
    count = 0
    for _ in range(10000):
        random.shuffle(combined)
        rank_sum = sum([combined.index(x) for x in seq1])
        if rank_sum <= n1 * (n1 + n2 + 1) / 2:
            count += 1
    return count / 10000

def main():
    seq1 = generate_sequence(50)
    seq2 = generate_sequence(50)
    pvalue = calculate_pvalue(seq1, seq2)
    print(pvalue)
main()