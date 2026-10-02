function align_sequences(seq1: string, seq2: string): number {
    const m = seq1.length, n = seq2.length;
    const dp: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

function process_sequences(sequences: string[]): [string, string, number][] {
    const results: [string, string, number][] = [];
    for (let i = 0; i < sequences.length - 1; i++) {
        for (let j = i + 1; j < sequences.length; j++) {
            results.push([sequences[i], sequences[j], align_sequences(sequences[i], sequences[j])]);
        }
    }
    return results;
}

function main() {
    const sequences = ['ATCG', 'AGCT', 'GCTA', 'CGTA'];
    const results = process_sequences(sequences);
    results.forEach(([seq1, seq2, score]) => {
        console.log(`Alignment between ${seq1} and ${seq2}: Score = ${score}`);
    });
}

main();