def generate_sequence(a, b, n):
    seq = [a, b]
    for _ in range(n - 2):
        seq.append(seq[-1] + seq[-2])
    return seq

def align_sequences(seq1, seq2):
    while True:
        if seq1 == seq2:
            return seq1
        if len(seq1) < len(seq2):
            seq1.append(seq1[-1] + seq1[-2])
        else:
            seq2.append(seq2[-1] + seq2[-2])

def main():
    seq1 = generate_sequence(1, 1, 10)
    seq2 = generate_sequence(2, 1, 10)
    aligned_seq = align_sequences(seq1, seq2)
    print(aligned_seq)
main()