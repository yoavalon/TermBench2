def align_sequences(seq1, seq2):
    m, n = (len(seq1), len(seq2))
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            cost = 0 if seq1[i - 1] == seq2[j - 1] else 1
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost)
    return dp[m][n]

def process_sequences(sequences):
    total_cost = 0
    for seq1, seq2 in sequences:
        total_cost += align_sequences(seq1, seq2)
    return total_cost

def main():
    sequences = [('AGCT', 'ACGT'), ('GATTACA', 'GCTACGA')]
    result = process_sequences(sequences)
    print(result)
main()