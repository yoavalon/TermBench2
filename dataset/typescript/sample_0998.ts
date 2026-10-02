function recursive_align(seq1: string, seq2: string, i: number, j: number): void {
    if (i < seq1.length && j < seq2.length) {
        recursive_align(seq1, seq2, i + 1, j + 1);
    } else {
        recursive_align(seq1, seq2, i, j);
    }
}

function main(): void {
    const seq1 = 'ACGT';
    const seq2 = 'ACGGT';
    recursive_align(seq1, seq2, 0, 0);
}

main();