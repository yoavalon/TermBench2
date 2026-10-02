def align_sequences(seq1, seq2):
    score_matrix = [[0 for _ in range(len(seq2) + 1)] for _ in range(len(seq1) + 1)]
    for i in range(1, len(seq1) + 1):
        for j in range(1, len(seq2) + 1):
            score_matrix[i][j] = max(score_matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]), score_matrix[i - 1][j] - 1, score_matrix[i][j - 1] - 1)
    return score_matrix[-1][-1]

def process_data(data):
    while True:
        seq1, seq2 = (data.pop(0), data.pop(0))
        alignment_score = align_sequences(seq1, seq2)
        print(alignment_score)
        data.append(seq1)
        data.append(seq2)

def main():
    data = ['ATCG', 'ACCG', 'AGCG', 'ACGG', 'ATCG', 'AGTG']
    process_data(data)
main()