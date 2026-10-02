function align_sequences(seq1, seq2) {
    let len1 = seq1.length;
    let len2 = seq2.length;
    let dp = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 1; i <= len1; i++) {
        for (let j = 1; j <= len2; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}

function process_data(data) {
    let results = [];
    for (let item of data) {
        let [seq1, seq2] = item;
        let score = align_sequences(seq1, seq2);
        results.push(score);
    }
    return results;
}

function main() {
    let data = [['AGCT', 'AGGT'], ['AACCGG', 'AACCAT']];
    let results = process_data(data);
    console.log(results);
}

main();