function boundary_conditions(seq1, seq2, max_length) {
    let i = 0, j = 0;
    while (i < seq1.length && j < seq2.length && (i + j < max_length)) {
        if (seq1[i] === seq2[j]) {
            i += 1;
            j += 1;
        } else {
            i += 1;
        }
    }
    return [i, j];
}
boundary_conditions('AGTAC', 'AGCTA', 10);