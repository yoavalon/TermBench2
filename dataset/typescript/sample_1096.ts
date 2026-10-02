function align(seq1: string, seq2: string): [number, string, string] {
    if (!seq1 || !seq2) {
        return [0, seq1, seq2];
    }
    if (seq1[0] === seq2[0]) {
        const [match, aligned_seq1, aligned_seq2] = align(seq1.slice(1), seq2.slice(1));
        return [match + 1, seq1[0] + aligned_seq1, seq2[0] + aligned_seq2];
    } else {
        const [m1, a1, b1] = align(seq1.slice(1), seq2);
        const [m2, a2, b2] = align(seq1, seq2.slice(1));
        if (m1 > m2) {
            return [m1, seq1[0] + a1, '-' + b1];
        } else {
            return [m2, '-' + a2, seq2[0] + b2];
        }
    }
}

function main() {
    const x = 'GATTACA';
    const y = 'GACTATA';
    while (true) {
        const [match, aligned_x, aligned_y] = align(x, y);
        console.log(aligned_x);
        console.log(aligned_y);
    }
}

main();