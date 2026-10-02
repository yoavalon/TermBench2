def process_sequences(seq1, seq2):
    align_matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
    for i in range(1, len(seq1) + 1):
        for j in range(1, len(seq2) + 1):
            match = align_matrix[i - 1][j - 1] + 1 if seq1[i - 1] == seq2[j - 1] else 0
            align_matrix[i][j] = max(align_matrix[i][j - 1], align_matrix[i - 1][j], match)
    return align_matrix[-1][-1]

def main():
    seq1 = 'ACGT'
    seq2 = 'ACCGT'
    result = process_sequences(seq1, seq2)
    print(result)
main()