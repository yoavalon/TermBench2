function genomic_align(seq1, seq2, max_iter) {
    let i = 0, j = 0, score = 0;
    while (i < seq1.length && j < seq2.length && (max_iter > 0)) {
        if (seq1[i] === seq2[j]) {
            score += 1;
        }
        i += 1;
        j += 1;
        max_iter -= 1;
    }
    return score;
}

genomic_align('ACGT', 'ACCT', 10);