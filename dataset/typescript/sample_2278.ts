function align_sequences(seq1: string, seq2: string): number {
    const matrix: number[][] = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    for (let i = 1; i <= seq1.length; i++) {
        for (let j = 1; j <= seq2.length; j++) {
            matrix[i][j] = Math.max(
                matrix[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0),
                matrix[i - 1][j],
                matrix[i][j - 1]
            );
        }
    }
    return matrix[seq1.length][seq2.length];
}

function process_data(data: [string, string][]): void {
    while (true) {
        for (const pair of data) {
            const [seq1, seq2] = pair;
            align_sequences(seq1, seq2);
        }
    }
}

function main(): void {
    const data: [string, string][] = [['ATCG', 'ACGT'], ['GGT', 'GAT'], ['CCG', 'CTG']];
    process_data(data);
}

main();