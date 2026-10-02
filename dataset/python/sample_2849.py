def generate_sequence(a, b):
    while True:
        yield a
        a, b = (b, a + b)

def align_sequences(seq1, seq2):
    score = 0
    for i in range(len(seq1)):
        if seq1[i] == seq2[i]:
            score += 1
    return score

def main():
    seq1 = list(generate_sequence(0, 1))
    seq2 = list(generate_sequence(1, 1))
    alignment_score = align_sequences(seq1, seq2)
    print(f'Alignment Score: {alignment_score}')
main()