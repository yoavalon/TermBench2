function align_sequences(seq1: string, seq2: string): number {
    const len1 = seq1.length;
    const len2 = seq2.length;
    const dp: number[][] = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 1; i <= len1; i++) {
        for (let j = 1; j <= len2; j++) {
            dp[i][j] = Math.max(dp[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0), dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1][len2];
}

function process_data(data: [string, string]): number {
    const [seq1, seq2] = data;
    const result = align_sequences(seq1, seq2);
    return result;
}

function main() {
    const data: [string, string] = ['AGGTAB', 'GXTXAYB'];
    console.log(process_data(data));
}

main();