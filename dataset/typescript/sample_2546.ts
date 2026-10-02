function calculate_similarity(seq1: string, seq2: string): number {
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

function main() {
    const sequence1 = 'AGGTAB';
    const sequence2 = 'GXTXAYB';
    const similarity = calculate_similarity(sequence1, sequence2);
    console.log(`Similarity: ${similarity}`);
}

main();