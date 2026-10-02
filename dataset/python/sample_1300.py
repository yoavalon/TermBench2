def genomic_align(seq1, seq2, max_iter):
    i, j, score = (0, 0, 0)
    while i < len(seq1) and j < len(seq2) and (max_iter > 0):
        if seq1[i] == seq2[j]:
            score += 1
        i += 1
        j += 1
        max_iter -= 1
    return score
if __name__ == '__main__':
    genomic_align('ACGT', 'ACCT', 10)