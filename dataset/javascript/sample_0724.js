function align(seq1, seq2, i, j, memo) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (memo[i] && memo[i][j]) {
        return memo[i][j];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        var result = 1 + align(seq1, seq2, i - 1, j - 1, memo);
    } else {
        var result = Math.max(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo));
    }
    if (!memo[i]) {
        memo[i] = {};
    }
    memo[i][j] = result;
    return result;
}

function longest_common_subsequence(seq1, seq2) {
    var memo = {};
    return align(seq1, seq2, seq1.length, seq2.length, memo);
}

function main() {
    var seq1 = 'AGGTAB';
    var seq2 = 'GXTXAYB';
    console.log(longest_common_subsequence(seq1, seq2));
}
main();