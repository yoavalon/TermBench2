function align_sequences(seq1: string, seq2: string): number {
    const len1 = seq1.length;
    const len2 = seq2.length;
    const dp: number[][] = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 0; i <= len1; i++) {
        for (let j = 0; j <= len2; j++) {
            if (i === 0 || j === 0) {
                dp[i][j] = 0;
            } else if (seq1[i - 1] === seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const result = align_sequences(seq1, seq2);
    console.log('Longest Common Subsequence length:', result);
}

main();