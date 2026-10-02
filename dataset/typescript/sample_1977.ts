import * as math from 'mathjs';

function calculate_similarity(seq1: string, seq2: string): number {
    const length = Math.min(seq1.length, seq2.length);
    let identical = 0;
    for (let i = 0; i < length; i++) {
        if (seq1[i] === seq2[i]) {
            identical++;
        }
    }
    return identical / length;
}

function normalize_score(score: number): number {
    return Math.round(score * 100) / 100;
}

function main() {
    const sequence_a = 'ACGTACGTACGT';
    const sequence_b = 'ACGTACGTACGA';
    const similarity_score = calculate_similarity(sequence_a, sequence_b);
    const normalized_score = normalize_score(similarity_score);
    console.log(normalized_score);
}

if (require.main === module) {
    main();
}