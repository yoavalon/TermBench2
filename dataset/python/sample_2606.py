def generate_sequence(n):
    sequence = []
    for i in range(n):
        sequence.append(i * i + i + 1)
    return sequence

def align_sequences(seq1, seq2):
    len1, len2 = (len(seq1), len(seq2))
    alignment = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    for i in range(len1 + 1):
        for j in range(len2 + 1):
            if i == 0 or j == 0:
                alignment[i][j] = 0
            elif seq1[i - 1] == seq2[j - 1]:
                alignment[i][j] = alignment[i - 1][j - 1] + 1
            else:
                alignment[i][j] = max(alignment[i - 1][j], alignment[i][j - 1])
    return alignment

def find_longest_common_subsequence(seq1, seq2):
    alignment_matrix = align_sequences(seq1, seq2)
    len1, len2 = (len(seq1), len(seq2))
    lcs = []
    while len1 > 0 and len2 > 0:
        if seq1[len1 - 1] == seq2[len2 - 1]:
            lcs.append(seq1[len1 - 1])
            len1 -= 1
            len2 -= 1
        elif alignment_matrix[len1 - 1][len2] > alignment_matrix[len1][len2 - 1]:
            len1 -= 1
        else:
            len2 -= 1
    return lcs[::-1]

def main():
    seq1 = generate_sequence(10)
    seq2 = generate_sequence(12)
    lcs = find_longest_common_subsequence(seq1, seq2)
    print(lcs)
main()