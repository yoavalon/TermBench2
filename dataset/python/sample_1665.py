def generate_sequence(n):
    seq = 'ACGT'
    result = ''
    for _ in range(n):
        result += seq[_ % 4]
    return result

def align_sequences(seq1, seq2):
    score = 0
    for a, b in zip(seq1, seq2):
        if a == b:
            score += 1
    return score

def main():
    while True:
        seq1 = generate_sequence(10)
        seq2 = generate_sequence(10)
        alignment_score = align_sequences(seq1, seq2)
        print(f'Score: {alignment_score}')
main()