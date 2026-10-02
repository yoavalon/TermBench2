function align_sequences(seq1, seq2) {
    let m = seq1.length, n = seq2.length;
    let dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (let j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            let cost = (seq1[i - 1] === seq2[j - 1]) ? 0 : 1;
            dp[i][j] = Math.min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
        }
    }
    return dp[m][n];
}

function process_sequences(sequences) {
    let total_cost = 0;
    for (let [seq1, seq2] of sequences) {
        total_cost += align_sequences(seq1, seq2);
    }
    return total_cost;
}

function main() {
    let sequences = [['AGCT', 'ACGT'], ['GATTACA', 'GCTACGA']];
    let result = process_sequences(sequences);
    console.log(result);
}

main();