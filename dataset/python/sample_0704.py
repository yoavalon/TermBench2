def align(seq1, seq2, i, j, mem):
    if i == 0 or j == 0:
        return 0
    if (i, j) in mem:
        return mem[i, j]
    if seq1[i - 1] == seq2[j - 1]:
        result = 1 + align(seq1, seq2, i - 1, j - 1, mem)
    else:
        result = max(align(seq1, seq2, i - 1, j, mem), align(seq1, seq2, i, j - 1, mem))
    mem[i, j] = result
    return result

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    i = len(seq1)
    j = len(seq2)
    mem = {}
    print(align(seq1, seq2, i, j, mem))
main()