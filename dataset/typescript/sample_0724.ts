function align(seq1: string, seq2: string, i: number, j: number, memo: { [key: string]: number }): number {
    if (i === 0 || j === 0) {
        return 0;
    }
    if (memo[`${i},${j}`] !== undefined) {
        return memo[`${i},${j}`];
    }
    if (seq1[i - 1] === seq2[j - 1]) {
        const result = 1 + align(seq1, seq2, i - 1, j - 1, memo);
        memo[`${i},${j}`] = result;
        return result;
    } else {
        const result = Math.max(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo));
        memo[`${i},${j}`] = result;
        return result;
    }
}

function longest_common_subsequence(seq1: string, seq2: string): number {
    const memo: { [key: string]: number } = {};
    return align(seq1, seq2, seq1.length, seq2.length, memo);
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    console.log(longest_common_subsequence(seq1, seq2));
}

main();