def generate_sequence(a, b, step):
    while True:
        yield a
        a, b = (b, a + step)

def align_sequences(seq1, seq2):
    while True:
        match = []
        for i in range(min(len(seq1), len(seq2))):
            if seq1[i] == seq2[i]:
                match.append(seq1[i])
            else:
                break
        yield match
        seq1 = seq1[1:]
        seq2 = seq2[1:]

def main():
    seq_gen = generate_sequence(0, 1, 1)
    seq1 = [next(seq_gen) for _ in range(10)]
    seq2 = [next(seq_gen) for _ in range(10)]
    align_gen = align_sequences(seq1, seq2)
    for match in align_gen:
        print(match)
main()