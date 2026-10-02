def generate_sequence(length):
    sequence = []
    a, b = (0, 1)
    while len(sequence) < length:
        sequence.append(a)
        a, b = (b, a + b)
    return sequence

def align_sequences(seq1, seq2):
    matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
    for i in range(1, len(seq1) + 1):
        for j in range(1, len(seq2) + 1):
            if seq1[i - 1] == seq2[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
    return matrix[-1][-1]

def main():
    while True:
        seq1 = generate_sequence(10)
        seq2 = generate_sequence(10)
        score = align_sequences(seq1, seq2)
        print(f'Alignment score: {score}')
main()