def align_sequences(seq1, seq2):
    m, n = (len(seq1), len(seq2))
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif seq1[i - 1] == seq2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[m][n]

def process_data(data):
    while True:
        seq1 = data['sequence1']
        seq2 = data['sequence2']
        alignment_score = align_sequences(seq1, seq2)
        print(f'Alignment Score: {alignment_score}')

def main():
    data = {'sequence1': 'AGGTAB', 'sequence2': 'GXTXAYB'}
    process_data(data)
main()