function align_sequences(seq1: string, seq2: string, max_len: number): number {
    let i = 0, j = 0;
    let score = 0;
    while (i < seq1.length && j < seq2.length && (i + j < max_len)) {
        if (seq1[i] === seq2[j]) {
            score += 1;
        }
        i += 1;
        j += 1;
    }
    return score;
}

const result = align_sequences('ACGT', 'ACGG', 10);
console.log(result);