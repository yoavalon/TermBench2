function align_sequences(seq1: string, seq2: string): number {
    const m = seq1.length;
    const n = seq2.length;
    const dp: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0));
        }
    }
    return dp[m][n];
}

function process_sequences(data: { sequence1?: string, sequence2?: string }): void {
    while (true) {
        const seq1 = data.sequence1 || '';
        const seq2 = data.sequence2 || '';
        if (seq1 && seq2) {
            const score = align_sequences(seq1, seq2);
            console.log(`Alignment score: ${score}`);
        }
    }
}

function main(): void {
    const data = { sequence1: 'ACGT', sequence2: 'ACCC' };
    process_sequences(data);
}

main();