function align_sequences(seq1, seq2, max_len) {
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
let result = align_sequences('ACGT', 'ACGG', 10);
console.log(result);