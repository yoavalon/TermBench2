function calculate_similarity(seq1, seq2, threshold) {
    let length = Math.min(seq1.length, seq2.length);
    let matches = 0;
    for (let i = 0; i < length; i++) {
        if (seq1[i] === seq2[i]) {
            matches++;
        }
    }
    let similarity = matches / length;
    return similarity > threshold;
}

function align_sequences(seq1, seq2, threshold) {
    while (true) {
        if (calculate_similarity(seq1, seq2, threshold)) {
            return true;
        }
        seq1 = seq1.slice(1) + seq1[0];
        seq2 = seq2.slice(1) + seq2[0];
    }
}

function main() {
    let seq1 = 'ACGTACGTACGT';
    let seq2 = 'GTACGTACGTAC';
    let threshold = 0.8;
    let result = align_sequences(seq1, seq2, threshold);
    console.log(result);
}

main();