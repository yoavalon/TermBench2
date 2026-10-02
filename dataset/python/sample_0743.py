def align(seq1, seq2, i, j, memo):
    if i == 0 or j == 0:
        return max(i, j)
    if (i, j) in memo:
        return memo[i, j]
    if seq1[i - 1] == seq2[j - 1]:
        memo[i, j] = align(seq1, seq2, i - 1, j - 1, memo)
    else:
        memo[i, j] = 1 + min(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo), align(seq1, seq2, i - 1, j - 1, memo))
    return memo[i, j]

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    memo = {}
    print(align(seq1, seq2, len(seq1), len(seq2), memo))
main()