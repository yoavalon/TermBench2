function align_sequences(seq1, seq2) {
    var m = seq1.length, n = seq2.length;
    var dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (var i = 1; i <= m; i++) {
        for (var j = 1; j <= n; j++) {
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
    var seq1 = 'AGCTG';
    var seq2 = 'GCTAG';
    while (true) {
        var score = align_sequences(seq1, seq2);
        console.log('Alignment Score:', score);
    }
}

main();