def calculate_similarity(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if seq1[i - 1] == seq2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[len1][len2]

def main():
    sequence1 = 'AGGTAB'
    sequence2 = 'GXTXAYB'
    similarity = calculate_similarity(sequence1, sequence2)
    print(f'Similarity: {similarity}')
main()