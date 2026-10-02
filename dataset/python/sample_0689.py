def align(a, b, i, j):
    if i == 0 or j == 0:
        return 0
    elif a[i - 1] == b[j - 1]:
        return align(a, b, i - 1, j - 1) + 1
    else:
        return max(align(a, b, i - 1, j), align(a, b, i, j - 1))

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    result = align(seq1, seq2, len(seq1), len(seq2))
    print(result)
main()