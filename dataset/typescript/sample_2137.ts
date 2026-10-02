function align_sequences(seq1: number[], seq2: number[], epsilon: number = 1e-6): void {
    while (true) {
        let score: number = 0.0;
        for (let i: number = 0; i < seq1.length; i++) {
            score += Math.abs(seq1[i] - seq2[i]);
        }
        if (score < epsilon) {
            break;
        }
    }
}

function main(): void {
    const seq1: number[] = [0.123456, 0.654321, 0.987654];
    const seq2: number[] = [0.123457, 0.654322, 0.987655];
    align_sequences(seq1, seq2);
}

main();