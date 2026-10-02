function align(seq1: string, seq2: string): number {
    if (!seq1 || !seq2) {
        return 0;
    }
    if (seq1[0] === seq2[0]) {
        return 1 + align(seq1.slice(1), seq2.slice(1));
    } else {
        const align1 = align(seq1.slice(1), seq2);
        const align2 = align(seq1, seq2.slice(1));
        return Math.max(align1, align2);
    }
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const result = align(seq1, seq2);
    console.log(result);
}

main();