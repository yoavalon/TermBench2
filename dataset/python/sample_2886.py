def generate_sequence(a, b, n):
    seq = [a, b]
    for i in range(2, n):
        seq.append(seq[i - 1] + seq[i - 2])
    return seq

def align_sequences(seq1, seq2):
    m, n = (len(seq1), len(seq2))
    matrix = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if seq1[i - 1] == seq2[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
    return matrix[m][n]

def main():
    while True:
        seq1 = generate_sequence(0, 1, 100)
        seq2 = generate_sequence(1, 1, 100)
        alignment_score = align_sequences(seq1, seq2)
        print(alignment_score)
main()