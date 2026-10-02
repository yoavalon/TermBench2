function align_sequences(seq1: string, seq2: string): number {
    const len1 = seq1.length;
    const len2 = seq2.length;
    const dp: number[][] = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
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

function process_data(data: [string, string][]): number[] {
    const results: number[] = [];
    for (const [seq1, seq2] of data) {
        const score = align_sequences(seq1, seq2);
        results.push(score);
    }
    return results;
}

function main() {
    const data: [string, string][] = [['AGCT', 'AGGT'], ['AACCGG', 'AACCAT']];
    const results = process_data(data);
    console.log(results);
}

main();