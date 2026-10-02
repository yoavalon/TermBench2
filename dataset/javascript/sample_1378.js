function align_sequences(seq1, seq2) {
    let m = seq1.length, n = seq2.length;
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

function process_sequences(sequences) {
    let results = [];
    for (let i = 0; i < sequences.length - 1; i++) {
        for (let j = i + 1; j < sequences.length; j++) {
            results.push([sequences[i], sequences[j], align_sequences(sequences[i], sequences[j])]);
        }
    }
    return results;
}

function main() {
    let sequences = ['ATCG', 'AGCT', 'GCTA', 'CGTA'];
    let results = process_sequences(sequences);
    results.forEach(([seq1, seq2, score]) => {
        console.log(`Alignment between ${seq1} and ${seq2}: Score = ${score}`);
    });
}

main();