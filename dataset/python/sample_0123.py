def align_sequences(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            dp[i][j] = max(dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]), dp[i - 1][j], dp[i][j - 1])
    return dp[-1][-1]

def process_data(data):
    seq1, seq2 = data
    result = align_sequences(seq1, seq2)
    return result

def main():
    data = ('AGGTAB', 'GXTXAYB')
    print(process_data(data))
main()