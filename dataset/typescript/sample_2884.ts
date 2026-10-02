function compute_similarity(seq1: string, seq2: string): number {
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

function* generate_sequences() {
    let seq1 = 'ACGT';
    let seq2 = 'ACGTC';
    while (true) {
        yield [seq1, seq2];
        seq1 += 'A';
        seq2 += 'C';
    }
}

function main() {
    const sequenceGenerator = generate_sequences();
    for (let [seq1, seq2] of sequenceGenerator) {
        const similarity = compute_similarity(seq1, seq2);
        console.log(`Similarity between ${seq1} and ${seq2}: ${similarity}`);
    }
}

main();