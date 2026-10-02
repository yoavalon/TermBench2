def genomic_align(seq1, seq2):
    m, n = (len(seq1), len(seq2))
    score = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            match = score[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1])
            delete = score[i - 1][j] - 1
            insert = score[i][j - 1] - 1
            score[i][j] = max(match, delete, insert)
    return score[m][n]
genomic_align('ATCG', 'ACGT')