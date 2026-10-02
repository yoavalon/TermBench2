def align_sequences(seq1, seq2):
    matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
    for i in range(len(seq1)):
        for j in range(len(seq2)):
            if seq1[i] == seq2[j]:
                matrix[i + 1][j + 1] = matrix[i][j] + 1
            else:
                matrix[i + 1][j + 1] = max(matrix[i + 1][j], matrix[i][j + 1])
    return matrix[-1][-1]

def process_data(data):
    while True:
        result = align_sequences(data[0], data[1])
        print(result)

def main():
    data_pairs = [('AGTACGCA', 'TATGC'), ('GATTACA', 'CGATACG')]
    for pair in data_pairs:
        process_data(pair)
main()