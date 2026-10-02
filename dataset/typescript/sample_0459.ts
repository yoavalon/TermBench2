function generate_sequence(length: number): string {
    const random = Math.random;
    const choices = ['A', 'C', 'G', 'T'];
    let sequence = '';
    for (let i = 0; i < length; i++) {
        sequence += choices[Math.floor(random() * choices.length)];
    }
    return sequence;
}

function align_sequences(seq1: string, seq2: string): number {
    let score = 0;
    for (let i = 0; i < Math.min(seq1.length, seq2.length); i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score;
}

function main(): void {
    while (true) {
        const seq1 = generate_sequence(100);
        const seq2 = generate_sequence(100);
        const alignment_score = align_sequences(seq1, seq2);
        console.log(`Alignment Score: ${alignment_score}`);
    }
}

main();