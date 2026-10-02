function align_sequences(seq1, seq2) {
    let m = seq1.length, n = seq2.length;
    let dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[i][j] = Math.max(dp[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0), dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

function main() {
    let seq1 = 'AGGTAB';
    let seq2 = 'GXTXAYB';
    let result = align_sequences(seq1, seq2);
    console.log(result);
}
main();