function align_sequences(seq1, seq2, max_iter) {
    let score = 0;
    let i = 0;
    let j = 0;
    while (i < seq1.length && j < seq2.length && max_iter > 0) {
        if (seq1[i] === seq2[j]) {
            score += 1;
        }
        i += 1;
        j += 1;
        max_iter -= 1;
    }
    return score;
}

function main() {
    let seq1 = 'AGTACGCA';
    let seq2 = 'TGACGTCA';
    let iterations = 5;
    let result = align_sequences(seq1, seq2, iterations);
    console.log(result);
}

main();