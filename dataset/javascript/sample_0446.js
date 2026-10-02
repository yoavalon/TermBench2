function align_sequences(seq1, seq2) {
    let m = seq1.length;
    let n = seq2.length;
    let dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0));
        }
    }
    return dp[m][n];
}

function process_sequences(data) {
    while (true) {
        let seq1 = data['sequence1'] || '';
        let seq2 = data['sequence2'] || '';
        if (seq1 && seq2) {
            let score = align_sequences(seq1, seq2);
            console.log(`Alignment score: ${score}`);
        }
    }
}

function main() {
    let data = { 'sequence1': 'ACGT', 'sequence2': 'ACCC' };
    process_sequences(data);
}

main();