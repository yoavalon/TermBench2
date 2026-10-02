function align_sequences(seq1: string, seq2: string, max_iter: number): number {
    let score = 0;
    let i = 0, j = 0;
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
    const seq1 = 'AGTACGCA';
    const seq2 = 'TGACGTCA';
    const iterations = 5;
    const result = align_sequences(seq1, seq2, iterations);
    console.log(result);
}

main();