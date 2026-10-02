def align_sequences(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if seq1[i - 1] == seq2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[len1][len2]

def process_data(data):
    results = []
    for item in data:
        seq1, seq2 = item
        score = align_sequences(seq1, seq2)
        results.append(score)
    return results

def main():
    data = [('AGCT', 'AGGT'), ('AACCGG', 'AACCAT')]
    results = process_data(data)
    print(results)
if __name__ == '__main__':
    main()