def align_sequences(seq1, seq2, max_iter):
    score = 0
    i, j = (0, 0)
    while i < len(seq1) and j < len(seq2) and (max_iter > 0):
        if seq1[i] == seq2[j]:
            score += 1
        i += 1
        j += 1
        max_iter -= 1
    return score

def main():
    seq1 = 'AGTACGCA'
    seq2 = 'TGACGTCA'
    iterations = 5
    result = align_sequences(seq1, seq2, iterations)
    print(result)
main()