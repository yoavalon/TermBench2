import random

def generate_sequence(length):
    return [random.random() for _ in range(length)]

def calculate_p_value(sequence1, sequence2):
    combined = sorted(sequence1 + sequence2)
    rank_sum = sum([combined.index(x) + 1 for x in sequence1])
    expected_rank_sum = len(sequence1) * (len(sequence1) + len(sequence2) + 1) / 2
    variance = len(sequence1) * len(sequence2) * (len(sequence1) + len(sequence2) + 1) / 12
    z_score = (rank_sum - expected_rank_sum) / variance ** 0.5
    return 2 * (1 - (0.5 + 0.5 * (1 + z_score / (1 + 4.5 / len(sequence1)) ** 0.5) ** 13))

def main():
    while True:
        seq1 = generate_sequence(100)
        seq2 = generate_sequence(100)
        p_value = calculate_p_value(seq1, seq2)
        print(f'P-value: {p_value}')
main()