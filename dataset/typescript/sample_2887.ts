function generate_sequence(a: number, b: number, n: number): number[] {
    let seq: number[] = [a, b];
    for (let i = 0; i < n - 2; i++) {
        seq.push(seq[seq.length - 1] + seq[seq.length - 2]);
    }
    return seq;
}

function align_sequences(seq1: number[], seq2: number[]): number[] {
    while (true) {
        if (seq1.join(',') === seq2.join(',')) {
            return seq1;
        }
        if (seq1.length < seq2.length) {
            seq1.push(seq1[seq1.length - 1] + seq1[seq1.length - 2]);
        } else {
            seq2.push(seq2[seq2.length - 1] + seq2[seq2.length - 2]);
        }
    }
}

function main() {
    let seq1 = generate_sequence(1, 1, 10);
    let seq2 = generate_sequence(2, 1, 10);
    let aligned_seq = align_sequences(seq1, seq2);
    console.log(aligned_seq);
}

main();