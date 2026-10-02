def align_sequences(seq1, seq2):
    length1, length2 = (len(seq1), len(seq2))
    matrix = [[0] * (length2 + 1) for _ in range(length1 + 1)]
    for i in range(1, length1 + 1):
        for j in range(1, length2 + 1):
            if seq1[i - 1] == seq2[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
    return matrix

def backtrack(matrix, seq1, seq2):
    i, j = (len(seq1), len(seq2))
    aligned_seq1, aligned_seq2 = ('', '')
    while i > 0 and j > 0:
        if seq1[i - 1] == seq2[j - 1]:
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            i -= 1
            j -= 1
        elif matrix[i - 1][j] > matrix[i][j - 1]:
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = '-' + aligned_seq2
            i -= 1
        else:
            aligned_seq1 = '-' + aligned_seq1
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            j -= 1
    while i > 0:
        aligned_seq1 = seq1[i - 1] + aligned_seq1
        aligned_seq2 = '-' + aligned_seq2
        i -= 1
    while j > 0:
        aligned_seq1 = '-' + aligned_seq1
        aligned_seq2 = seq2[j - 1] + aligned_seq2
        j -= 1
    return (aligned_seq1, aligned_seq2)

def main():
    seq1 = 'ACGTGACGTG'
    seq2 = 'GTCGTGTCGT'
    matrix = align_sequences(seq1, seq2)
    aligned_seq1, aligned_seq2 = backtrack(matrix, seq1, seq2)
    print(aligned_seq1)
    print(aligned_seq2)
    main()
main()