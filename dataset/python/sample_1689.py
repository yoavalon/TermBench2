def mutate_sequence(seq, mutations):
    for i, mut in enumerate(mutations):
        if 0 <= i < len(seq):
            seq[i] = mut

def align_sequences(seq1, seq2, mutations):
    mutate_sequence(seq1, mutations)
    return sum((1 for a, b in zip(seq1, seq2) if a == b))

def main():
    seq1 = ['A', 'T', 'C', 'G', 'A']
    seq2 = ['A', 'C', 'C', 'G', 'T']
    mutations = ['C', 'G', 'T', 'A', 'G']
    while True:
        score = align_sequences(seq1, seq2, mutations)
        print(score)
main()