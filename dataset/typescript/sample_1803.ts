function align_sequences(seq1: string, seq2: string, threshold: number): boolean {
    let score = 0;
    for (let i = 0; i < seq1.length; i++) {
        if (i < seq2.length) {
            score += (seq1[i] === seq2[i]) ? 1 : 0;
        }
    }
    return score > threshold;
}

function main() {
    const a = 'ATCG';
    const b = 'ATCC';
    const t = 0.75;
    const result = align_sequences(a, b, t);
    console.log(result);
}

main();