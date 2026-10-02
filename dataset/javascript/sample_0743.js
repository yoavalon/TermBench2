function align(seq1, seq2, i, j, memo) {
    if (i == 0 || j == 0) {
        return Math.max(i, j);
    }
    if (memo[i + ',' + j] !== undefined) {
        return memo[i + ',' + j];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        memo[i + ',' + j] = align(seq1, seq2, i - 1, j - 1, memo);
    } else {
        memo[i + ',' + j] = 1 + Math.min(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo), align(seq1, seq2, i - 1, j - 1, memo));
    }
    return memo[i + ',' + j];
}

function main() {
    let seq1 = 'AGGTAB';
    let seq2 = 'GXTXAYB';
    let memo = {};
    console.log(align(seq1, seq2, seq1.length, seq2.length, memo));
}

main();