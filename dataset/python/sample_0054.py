def align_sequences(seq1, seq2, max_len):
    i, j = (0, 0)
    score = 0
    while i < len(seq1) and j < len(seq2) and (i + j < max_len):
        if seq1[i] == seq2[j]:
            score += 1
        i += 1
        j += 1
    return score
result = align_sequences('ACGT', 'ACGG', 10)
print(result)