function align(seq1, seq2) {
    if (!seq1 || !seq2) {
        return 0;
    }
    if (seq1[0] === seq2[0]) {
        return 1 + align(seq1.slice(1), seq2.slice(1));
    } else {
        align1 = align(seq1.slice(1), seq2);
        align2 = align(seq1, seq2.slice(1));
        return Math.max(align1, align2);
    }
}

function main() {
    seq1 = 'AGGTAB';
    seq2 = 'GXTXAYB';
    result = align(seq1, seq2);
    console.log(result);
}
main();