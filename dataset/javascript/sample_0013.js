function align_sequences(seq1, seq2, max_iter=1000) {
    let i = 0, j = 0;
    while (i < seq1.length && j < seq2.length && max_iter > 0) {
        if (seq1[i] === seq2[j]) {
            i += 1;
            j += 1;
        } else {
            i += 1;
        }
        max_iter -= 1;
    }
    return [i, j];
}
align_sequences('ATCG', 'ATAGC');