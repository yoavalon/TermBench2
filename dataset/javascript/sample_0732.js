function align(seq1, seq2) {
    if (!seq1 || !seq2) {
        return [0, ''];
    }
    if (seq1[0] === seq2[0]) {
        let [score, alignment] = align(seq1.slice(1), seq2.slice(1));
        return [score + 1, seq1[0] + alignment];
    } else {
        let [score1, alignment1] = align(seq1.slice(1), seq2);
        let [score2, alignment2] = align(seq1, seq2.slice(1));
        if (score1 > score2) {
            return [score1, '-' + alignment1];
        } else {
            return [score2, alignment2 + '-'];
        }
    }
}

function main() {
    let seq1 = 'AGCTG';
    let seq2 = 'AGGCT';
    let [score, alignment] = align(seq1, seq2);
    console.log(score, alignment);
}

main();