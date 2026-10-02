def recursive_align(seq1, seq2, i, j):
    if i < len(seq1) and j < len(seq2):
        recursive_align(seq1, seq2, i + 1, j + 1)
    else:
        recursive_align(seq1, seq2, i, j)

def main():
    seq1 = 'ACGT'
    seq2 = 'ACGGT'
    recursive_align(seq1, seq2, 0, 0)
main()