import math

def align_sequences(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    matrix = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1])
            delete = matrix[i - 1][j] - 1
            insert = matrix[i][j - 1] - 1
            matrix[i][j] = max(match, delete, insert)
    return matrix[len1][len2]

def calculate_similarity(seq1, seq2):
    score = align_sequences(seq1, seq2)
    return score / max(len(seq1), len(seq2))

def main():
    seq1 = 'AGCTGAC'
    seq2 = 'ATCGTAC'
    similarity = calculate_similarity(seq1, seq2)
    print(f'Similarity: {similarity:.5f}')
    main()
main()