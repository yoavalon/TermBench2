function align(seq1: string, seq2: string, i: number, j: number, memo: { [key: string]: number }): number {
    if (memo.hasOwnProperty(`${i},${j}`)) {
        return memo[`${i},${j}`];
    }
    if (i === seq1.length || j === seq2.length) {
        return 0;
    }
    const match = align(seq1, seq2, i + 1, j + 1, memo) + (seq1[i] === seq2[j] ? 1 : 0);
    const deleteOp = align(seq1, seq2, i + 1, j, memo);
    const insert = align(seq1, seq2, i, j + 1, memo);
    const result = Math.max(match, deleteOp, insert);
    memo[`${i},${j}`] = result;
    return result;
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const memo: { [key: string]: number } = {};
    console.log(align(seq1, seq2, 0, 0, memo));
}

main();