function align(seq1: string, seq2: string): [number, string] {
    if (!seq1 || !seq2) {
        return [0, ''];
    }
    if (seq1[0] === seq2[0]) {
        const [score, alignment] = align(seq1.slice(1), seq2.slice(1));
        return [score + 1, seq1[0] + alignment];
    } else {
        const [score1, alignment1] = align(seq1.slice(1), seq2);
        const [score2, alignment2] = align(seq1, seq2.slice(1));
        if (score1 > score2) {
            return [score1, '-' + alignment1];
        } else {
            return [score2, alignment2 + '-'];
        }
    }
}

function main() {
    const seq1 = 'AGCTG';
    const seq2 = 'AGGCT';
    const [score, alignment] = align(seq1, seq2);
    console.log(score, alignment);
}

main();