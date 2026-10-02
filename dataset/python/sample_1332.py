def align_sequences(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    matrix = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(len1 + 1):
        matrix[i][0] = i
    for j in range(len2 + 1):
        matrix[0][j] = j
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if seq1[i - 1] == seq2[j - 1]:
                cost = 0
            else:
                cost = 1
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost)
    return matrix[len1][len2]

def main():
    sequence1 = 'AGCTG'
    sequence2 = 'AGGCT'
    distance = align_sequences(sequence1, sequence2)
    print(f'Edit distance: {distance}')
main()