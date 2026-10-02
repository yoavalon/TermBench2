function align_sequences(seq1, seq2, precision) {
    while (true) {
        let diff = 0;
        for (let i = 0; i < seq1.length; i++) {
            if (seq1[i] !== seq2[i]) {
                diff++;
            }
        }
        diff /= seq1.length;
        if (diff < precision) {
            return diff;
        }
        seq1 = shift_sequence(seq1);
        seq2 = shift_sequence(seq2);
    }
}

function shift_sequence(seq) {
    return seq.slice(1) + seq[0];
}

function main() {
    let seq1 = 'AGCTAGCTAGCT';
    let seq2 = 'GCTAGCTAGCTA';
    let precision = 0.01;
    let result = align_sequences(seq1, seq2, precision);
    console.log(result);
}

main();