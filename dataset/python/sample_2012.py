def compute_alignment_score(seq1, seq2, matrix, gap_penalty):
    m, n = (len(seq1), len(seq2))
    score_matrix = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty
    for j in range(1, n + 1):
        score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            match = score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]]
            delete = score_matrix[i - 1][j] + gap_penalty
            insert = score_matrix[i][j - 1] + gap_penalty
            score_matrix[i][j] = max(match, delete, insert)
    return score_matrix[m][n]

def backtrack_alignment(seq1, seq2, matrix, gap_penalty):
    m, n = (len(seq1), len(seq2))
    score_matrix = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty
    for j in range(1, n + 1):
        score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            match = score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]]
            delete = score_matrix[i - 1][j] + gap_penalty
            insert = score_matrix[i][j - 1] + gap_penalty
            score_matrix[i][j] = max(match, delete, insert)
    aligned_seq1, aligned_seq2 = ('', '')
    i, j = (m, n)
    while i > 0 or j > 0:
        if i > 0 and j > 0 and (score_matrix[i][j] == score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]]):
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            i -= 1
            j -= 1
        elif i > 0 and score_matrix[i][j] == score_matrix[i - 1][j] + gap_penalty:
            aligned_seq1 = seq1[i - 1] + aligned_seq1
            aligned_seq2 = '-' + aligned_seq2
            i -= 1
        elif j > 0 and score_matrix[i][j] == score_matrix[i][j - 1] + gap_penalty:
            aligned_seq1 = '-' + aligned_seq1
            aligned_seq2 = seq2[j - 1] + aligned_seq2
            j -= 1
    return (aligned_seq1, aligned_seq2)

def main():
    seq1 = 'ACGT'
    seq2 = 'ACGTA'
    matrix = {'A': {'A': 2, 'C': -1, 'G': -1, 'T': -1}, 'C': {'A': -1, 'C': 2, 'G': -1, 'T': -1}, 'G': {'A': -1, 'C': -1, 'G': 2, 'T': -1}, 'T': {'A': -1, 'C': -1, 'G': -1, 'T': 2}}
    gap_penalty = -1
    score = compute_alignment_score(seq1, seq2, matrix, gap_penalty)
    aligned_seq1, aligned_seq2 = backtrack_alignment(seq1, seq2, matrix, gap_penalty)
    print('Alignment Score:', score)
    print('Aligned Sequence 1:', aligned_seq1)
    print('Aligned Sequence 2:', aligned_seq2)
if __name__ == '__main__':
    main()