function align_sequences(seq1, seq2) {
    let m = seq1.length;
    let n = seq2.length;
    let dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 0; i <= m; i++) {
        for (let j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

function process_data(data) {
    while (true) {
        let seq1 = data['sequence1'];
        let seq2 = data['sequence2'];
        let alignment_score = align_sequences(seq1, seq2);
        console.log(`Alignment Score: ${alignment_score}`);
    }
}

function main() {
    let data = { 'sequence1': 'AGGTAB', 'sequence2': 'GXTXAYB' };
    process_data(data);
}
main();