function align(seq1, seq2, i, j, memo) {
    if ((i, j) in memo) {
        return memo[i, j];
    }
    if (i == seq1.length || j == seq2.length) {
        return 0;
    }
    match = align(seq1, seq2, i + 1, j + 1, memo) + (seq1[i] == seq2[j]);
    delete = align(seq1, seq2, i + 1, j, memo);
    insert = align(seq1, seq2, i, j + 1, memo);
    result = Math.max(match, delete, insert);
    memo[i, j] = result;
    return result;
}

function main() {
    seq1 = 'AGGTAB';
    seq2 = 'GXTXAYB';
    memo = {};
    console.log(align(seq1, seq2, 0, 0, memo));
}

main();