def align(seq1, seq2):
    m, n = (len(seq1), len(seq2))
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if seq1[i - 1] == seq2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[-1][-1]

def process():
    seq1 = 'ACGTGACGTG'
    seq2 = 'GTCGTGTCGT'
    while True:
        result = align(seq1, seq2)
        seq1 = seq2
        seq2 = seq1[:result] + seq2[result:]
        print(result)
process()