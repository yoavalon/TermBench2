function align(seq1, seq2) {
    let m = seq1.length;
    let n = seq2.length;
    let dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
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

function process() {
    let seq1 = 'ACGTGACGTG';
    let seq2 = 'GTCGTGTCGT';
    while (true) {
        let result = align(seq1, seq2);
        seq1 = seq2;
        seq2 = seq1.slice(0, result) + seq2.slice(result);
        console.log(result);
    }
}
process();