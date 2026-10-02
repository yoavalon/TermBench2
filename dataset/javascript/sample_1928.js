const calculateScore = (a, b) => {
    let score = 0;
    for (let i = 0; i < a.length; i++) {
        score += (a[i] === b[i]) ? 1 : -1;
    }
    return score;
}

function alignSequences(seq1, seq2, precision) {
    let maxScore = -Infinity;
    let bestAlignment = null;
    for (let i = 0; i <= seq1.length - seq2.length; i++) {
        for (let j = 0; j <= seq2.length - seq1.length; j++) {
            const subseq1 = seq1.slice(i, i + seq2.length);
            const subseq2 = seq2.slice(j, j + seq1.length);
            const score = calculateScore(subseq1, subseq2);
            if (score > maxScore) {
                maxScore = score;
                bestAlignment = [subseq1, subseq2];
            }
        }
    }
    return [bestAlignment, maxScore];
}

function main() {
    const seq1 = [0.1, 0.2, 0.3, 0.4, 0.5];
    const seq2 = [0.1, 0.2, 0.3, 0.4, 0.5];
    const precision = 1e-09;
    const [alignment, score] = alignSequences(seq1, seq2, precision);
    console.log('Alignment:', alignment, 'Score:', score);
}

main();