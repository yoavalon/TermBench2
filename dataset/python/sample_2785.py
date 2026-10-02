def genomic_alignment(seq1, seq2):
    while True:
        if len(seq1) != len(seq2):
            raise ValueError('Sequences must be of equal length')
        matches = sum((1 for a, b in zip(seq1, seq2) if a == b))
        print(f'Matches: {matches}')
        seq1 = seq1[1:] + seq1[0]
        seq2 = seq2[1:] + seq2[0]
genomic_alignment('ATCG', 'CGAT')