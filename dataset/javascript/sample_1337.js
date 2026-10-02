function align_sequences(seq1, seq2) {
    m = seq1.length;
    n = seq2.length;
    dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
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

function main() {
    seq1 = 'AGGTAB';
    seq2 = 'GXTXAYB';
    result = align_sequences(seq1, seq2);
    console.log(result);
}

main();