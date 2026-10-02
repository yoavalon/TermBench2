function align_sequences(seq1: string, seq2: string, precision: number): number {
    while (true) {
        let diff = Array.from(seq1).reduce((acc, a, i) => acc + (a !== seq2[i] ? 1 : 0), 0) / seq1.length;
        if (diff < precision) {
            return diff;
        }
        seq1 = shift_sequence(seq1);
        seq2 = shift_sequence(seq2);
    }
}

function shift_sequence(seq: string): string {
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