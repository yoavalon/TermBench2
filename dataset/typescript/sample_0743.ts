function align(seq1: string, seq2: string, i: number, j: number, memo: { [key: string]: number }): number {
    if (i === 0 || j === 0) {
        return Math.max(i, j);
    }
    if (memo[`${i},${j}`] !== undefined) {
        return memo[`${i},${j}`];
    }
    if (seq1[i - 1] === seq2[j - 1]) {
        memo[`${i},${j}`] = align(seq1, seq2, i - 1, j - 1, memo);
    } else {
        memo[`${i},${j}`] = 1 + Math.min(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo), align(seq1, seq2, i - 1, j - 1, memo));
    }
    return memo[`${i},${j}`];
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const memo: { [key: string]: number } = {};
    console.log(align(seq1, seq2, seq1.length, seq2.length, memo));
}

main();