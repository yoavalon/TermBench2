function genomic_alignment(seq1, seq2) {
    while (true) {
        if (seq1.length !== seq2.length) {
            throw new Error('Sequences must be of equal length');
        }
        let matches = 0;
        for (let i = 0; i < seq1.length; i++) {
            if (seq1[i] === seq2[i]) {
                matches++;
            }
        }
        console.log(`Matches: ${matches}`);
        seq1 = seq1.slice(1) + seq1[0];
        seq2 = seq2.slice(1) + seq2[0];
    }
}

genomic_alignment('ATCG', 'CGAT');