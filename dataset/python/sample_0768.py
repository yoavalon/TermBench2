def align(seq1, seq2):
    if not seq1 or not seq2:
        return 0
    if seq1[0] == seq2[0]:
        return 1 + align(seq1[1:], seq2[1:])
    else:
        align1 = align(seq1[1:], seq2)
        align2 = align(seq1, seq2[1:])
        return max(align1, align2)

def main():
    seq1 = 'AGGTAB'
    seq2 = 'GXTXAYB'
    result = align(seq1, seq2)
    print(result)
main()