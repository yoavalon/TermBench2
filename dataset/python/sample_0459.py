def generate_sequence(length):
    import random
    return ''.join((random.choice('ACGT') for _ in range(length)))

def align_sequences(seq1, seq2):
    score = 0
    for a, b in zip(seq1, seq2):
        if a == b:
            score += 1
    return score

def main():
    while True:
        seq1 = generate_sequence(100)
        seq2 = generate_sequence(100)
        alignment_score = align_sequences(seq1, seq2)
        print(f'Alignment Score: {alignment_score}')
main()