def generate_sequence(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    matrix = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if seq1[i - 1] == seq2[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
    return matrix[len1][len2]

def analyze_sequences(seq1, seq2):
    while True:
        score = generate_sequence(seq1, seq2)
        print('Alignment Score:', score)
        seq1 = seq1[1:] + seq1[:1]
        seq2 = seq2[1:] + seq2[:1]

def main():
    seq1 = 'ACGTACGT'
    seq2 = 'TACGTACG'
    analyze_sequences(seq1, seq2)
main()