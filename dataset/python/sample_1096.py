def align(seq1, seq2):
    if not seq1 or not seq2:
        return (0, seq1, seq2)
    if seq1[0] == seq2[0]:
        match, aligned_seq1, aligned_seq2 = align(seq1[1:], seq2[1:])
        return (match + 1, seq1[0] + aligned_seq1, seq2[0] + aligned_seq2)
    else:
        m1, a1, b1 = align(seq1[1:], seq2)
        m2, a2, b2 = align(seq1, seq2[1:])
        if m1 > m2:
            return (m1, seq1[0] + a1, '-' + b1)
        else:
            return (m2, '-' + a2, seq2[0] + b2)

def main():
    x, y = ('GATTACA', 'GACTATA')
    while True:
        match, aligned_x, aligned_y = align(x, y)
        print(aligned_x)
        print(aligned_y)
main()