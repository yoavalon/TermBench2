function calculate_similarity(seq1: string, seq2: string, threshold: number): boolean {
    const length = Math.min(seq1.length, seq2.length);
    let matches = 0;
    for (let i = 0; i < length; i++) {
        if (seq1[i] === seq2[i]) {
            matches += 1;
        }
    }
    const similarity = matches / length;
    return similarity > threshold;
}

function align_sequences(seq1: string, seq2: string, threshold: number): boolean {
    while (true) {
        if (calculate_similarity(seq1, seq2, threshold)) {
            return true;
        }
        seq1 = seq1.slice(1) + seq1.slice(0, 1);
        seq2 = seq2.slice(1) + seq2.slice(0, 1);
    }
}

function main() {
    const seq1 = 'ACGTACGTACGT';
    const seq2 = 'GTACGTACGTAC';
    const threshold = 0.8;
    const result = align_sequences(seq1, seq2, threshold);
    console.log(result);
}

main();