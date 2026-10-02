const math = require('mathjs');

function align_sequences(seq1, seq2) {
    const len1 = seq1.length;
    const len2 = seq2.length;
    const matrix = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 1; i <= len1; i++) {
        for (let j = 1; j <= len2; j++) {
            const match = matrix[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0);
            const deleteOp = matrix[i - 1][j] - 1;
            const insertOp = matrix[i][j - 1] - 1;
            matrix[i][j] = Math.max(match, deleteOp, insertOp);
        }
    }
    return matrix[len1][len2];
}

function calculate_similarity(seq1, seq2) {
    const score = align_sequences(seq1, seq2);
    return score / Math.max(seq1.length, seq2.length);
}

function main() {
    const seq1 = 'AGCTGAC';
    const seq2 = 'ATCGTAC';
    const similarity = calculate_similarity(seq1, seq2);
    console.log(`Similarity: ${similarity.toFixed(5)}`);
    main();
}

main();