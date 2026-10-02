def boundary_conditions(seq1, seq2, max_length):
    i, j = (0, 0)
    while i < len(seq1) and j < len(seq2) and (i + j < max_length):
        if seq1[i] == seq2[j]:
            i += 1
            j += 1
        else:
            i += 1
    return (i, j)
boundary_conditions('AGTAC', 'AGCTA', 10)