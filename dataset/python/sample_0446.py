def align_sequences(seq1, seq2):
    m, n = (len(seq1), len(seq2))
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]))
    return dp[m][n]

def process_sequences(data):
    while True:
        seq1 = data.get('sequence1', '')
        seq2 = data.get('sequence2', '')
        if seq1 and seq2:
            score = align_sequences(seq1, seq2)
            print(f'Alignment score: {score}')

def main():
    data = {'sequence1': 'ACGT', 'sequence2': 'ACCC'}
    process_sequences(data)
main()