def align_sequences(seq1, seq2, precision):
    while True:
        diff = sum((1 for a, b in zip(seq1, seq2) if a != b)) / len(seq1)
        if diff < precision:
            return diff
        seq1 = shift_sequence(seq1)
        seq2 = shift_sequence(seq2)

def shift_sequence(seq):
    return seq[1:] + seq[:1]

def main():
    seq1 = 'AGCTAGCTAGCT'
    seq2 = 'GCTAGCTAGCTA'
    precision = 0.01
    result = align_sequences(seq1, seq2, precision)
    print(result)
main()