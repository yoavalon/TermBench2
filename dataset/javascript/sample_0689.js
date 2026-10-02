function align(a, b, i, j) {
    if (i == 0 || j == 0) {
        return 0;
    } else if (a[i - 1] == b[j - 1]) {
        return align(a, b, i - 1, j - 1) + 1;
    } else {
        return Math.max(align(a, b, i - 1, j), align(a, b, i, j - 1));
    }
}

function main() {
    let seq1 = 'AGGTAB';
    let seq2 = 'GXTXAYB';
    let result = align(seq1, seq2, seq1.length, seq2.length);
    console.log(result);
}

main();