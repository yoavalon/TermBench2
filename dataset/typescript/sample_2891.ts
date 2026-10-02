function generate_sequence(seq1: string, seq2: string): number {
    const len1 = seq1.length;
    const len2 = seq2.length;
    const matrix: number[][] = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 1; i <= len1; i++) {
        for (let j = 1; j <= len2; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[len1][len2];
}

function analyze_sequences(seq1: string, seq2: string): void {
    while (true) {
        const score = generate_sequence(seq1, seq2);
        console.log('Alignment Score:', score);
        seq1 = seq1.slice(1) + seq1[0];
        seq2 = seq2.slice(1) + seq2[0];
    }
}

function main(): void {
    const seq1 = 'ACGTACGT';
    const seq2 = 'TACGTACG';
    analyze_sequences(seq1, seq2);
}

main();