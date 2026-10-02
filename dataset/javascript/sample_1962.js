const math = require('mathjs');

function align_sequences(seq1, seq2) {
    const len1 = seq1.length;
    const len2 = seq2.length;
    if (!len1 || !len2) {
        return 0;
    }
    let score = 0;
    for (let i = 0; i < Math.min(len1, len2); i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score / Math.max(len1, len2);
}

function normalize_score(score) {
    return Math.floor(score * 100) / 100;
}

function main() {
    const seq1 = 'ATCGTACG';
    const seq2 = 'ATCGTACC';
    const score = align_sequences(seq1, seq2);
    const normalized_score = normalize_score(score);
    console.log(normalized_score);
}

main();