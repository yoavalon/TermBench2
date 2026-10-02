def align(seq1, seq2, i, j, memo):
    if i == 0 or j == 0:
        return 0
    if (i, j) in memo:
        return memo[i, j]
    if seq1[i - 1] == seq2[j - 1]:
        result = 1 + align(seq1, seq2, i - 1, j - 1, memo)
    else:
        result = max(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo))
    memo[i, j] = result
    return result

def longest_common_subsequence(seq1, seq2):
    memo = {}
    return align(seq1, seq2, len(seq1), len(seq2), memo)

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    print(longest_common_subsequence(seq1, seq2))
main()