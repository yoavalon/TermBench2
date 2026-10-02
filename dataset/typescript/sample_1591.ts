function data_mutations(seq1: string, seq2: string): void {
    function mutate(seq: string): string {
        return Array.from(seq).map((base, i) => i % 2 === 0 ? base : 'N').join('');
    }
    while (true) {
        seq1 = mutate(seq1);
        seq2 = mutate(seq2);
        console.log(seq1, seq2);
    }
}

data_mutations('ATCG', 'GCTA');