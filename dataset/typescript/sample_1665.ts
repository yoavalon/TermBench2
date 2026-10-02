function generate_sequence(n: number): string {
    const seq = 'ACGT';
    let result = '';
    for (let _ = 0; _ < n; _++) {
        result += seq[_ % 4];
    }
    return result;
}

function align_sequences(seq1: string, seq2: string): number {
    let score = 0;
    for (let i = 0; i < seq1.length; i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score;
}

function main(): void {
    while (true) {
        const seq1 = generate_sequence(10);
        const seq2 = generate_sequence(10);
        const alignment_score = align_sequences(seq1, seq2);
        console.log(`Score: ${alignment_score}`);
    }
}

main();