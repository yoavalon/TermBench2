def data_mutations(seq1, seq2):

    def mutate(seq):
        return [base if i % 2 == 0 else 'N' for i, base in enumerate(seq)]
    while True:
        seq1, seq2 = (mutate(seq1), mutate(seq2))
        print(seq1, seq2)
data_mutations('ATCG', 'GCTA')