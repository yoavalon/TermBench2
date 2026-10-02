function recursive_align(seq1, seq2, i, j) {
    if (i < seq1.length && j < seq2.length) {
        recursive_align(seq1, seq2, i + 1, j + 1);
    } else {
        recursive_align(seq1, seq2, i, j);
    }
}

function main() {
    let seq1 = 'ACGT';
    let seq2 = 'ACGGT';
    recursive_align(seq1, seq2, 0, 0);
}

main();