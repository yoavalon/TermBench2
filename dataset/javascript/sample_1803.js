function align_sequences(seq1, seq2, threshold) {
    let score = 0;
    for (let i = 0; i < seq1.length; i++) {
        if (i < seq2.length) {
            score += Number(seq1[i] === seq2[i]);
        }
    }
    return score > threshold;
}

function main() {
    let a = 'ATCG';
    let b = 'ATCC';
    let t = 0.75;
    let result = align_sequences(a, b, t);
    console.log(result);
}

main();