import * as np from 'numpy';

function align_sequences(seq1: number[], seq2: number[], precision: number): [number[], number[], number] {
    function calculate_score(a: number[], b: number[]): number {
        let sum = 0;
        for (let i = 0; i < a.length; i++) {
            sum += a[i] === b[i] ? 1 : -1;
        }
        return sum;
    }

    let max_score = -Infinity;
    let best_alignment: [number[], number[]] = [ [], [] ];
    for (let i = 0; i <= seq1.length - seq2.length; i++) {
        for (let j = 0; j <= seq2.length - seq1.length; j++) {
            const subseq1 = seq1.slice(i, i + seq2.length);
            const subseq2 = seq2.slice(j, j + seq1.length);
            const score = calculate_score(subseq1, subseq2);
            if (score > max_score) {
                max_score = score;
                best_alignment = [subseq1, subseq2];
            }
        }
    }
    return [best_alignment[0], best_alignment[1], max_score];
}

function main() {
    const seq1 = [0.1, 0.2, 0.3, 0.4, 0.5];
    const seq2 = [0.1, 0.2, 0.3, 0.4, 0.5];
    const precision = 1e-09;
    const [alignment1, alignment2, score] = align_sequences(seq1, seq2, precision);
    console.log('Alignment:', alignment1, alignment2, 'Score:', score);
}

main();