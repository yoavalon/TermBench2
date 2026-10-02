function* generate_sequence(a: number, b: number): Generator<number> {
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

function align_sequences(seq1: number[], seq2: number[]): number {
    let score = 0;
    for (let i = 0; i < seq1.length; i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score;
}

function main() {
    const seq1 = Array.from(generate_sequence(0, 1));
    const seq2 = Array.from(generate_sequence(1, 1));
    const alignment_score = align_sequences(seq1, seq2);
    console.log(`Alignment Score: ${alignment_score}`);
}

main();