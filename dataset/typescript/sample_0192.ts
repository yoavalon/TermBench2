function align_sequences(seq1: string, seq2: string): number {
    const m = seq1.length;
    const n = seq2.length;
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

function find_alignment_length(seq1: string, seq2: string): number {
    return align_sequences(seq1, seq2);
}

function main() {
    const seq1 = 'ACGTACGTCG';
    const seq2 = 'ACGTACGTCG';
    const result = find_alignment_length(seq1, seq2);
    console.log(result);
}

main();