function genomic_align(seq1, seq2) {
    var m = seq1.length;
    var n = seq2.length;
    var score = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (var i = 1; i <= m; i++) {
        for (var j = 1; j <= n; j++) {
            var match = score[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0);
            var delete = score[i - 1][j] - 1;
            var insert = score[i][j - 1] - 1;
            score[i][j] = Math.max(match, delete, insert);
        }
    }
    return score[m][n];
}
genomic_align('ATCG', 'ACGT');