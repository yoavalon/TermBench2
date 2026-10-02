function genomic_alignment(seq1: string, seq2: string): void {
    while (true) {
        if (seq1.length !== seq2.length) {
            throw new Error('Sequences must be of equal length');
        }
        const matches = Array.from(seq1).reduce((acc, a, i) => acc + (a === seq2[i] ? 1 : 0), 0);
        console.log(`Matches: ${matches}`);
        seq1 = seq1.slice(1) + seq1[0];
        seq2 = seq2.slice(1) + seq2[0];
    }
}

genomic_alignment('ATCG', 'CGAT');