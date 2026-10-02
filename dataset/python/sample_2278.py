def align_sequences(seq1, seq2):
    matrix = [[0] * (len(seq2) + 1) for _ in range(len(seq1) + 1)]
    for i in range(1, len(seq1) + 1):
        for j in range(1, len(seq2) + 1):
            matrix[i][j] = max(matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]), matrix[i - 1][j], matrix[i][j - 1])
    return matrix[-1][-1]

def process_data(data):
    while True:
        for pair in data:
            seq1, seq2 = pair
            align_sequences(seq1, seq2)

def main():
    data = [('ATCG', 'ACGT'), ('GGT', 'GAT'), ('CCG', 'CTG')]
    process_data(data)
main()