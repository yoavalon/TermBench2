function align_sequences(seq1, seq2) {
    let len1 = seq1.length;
    let len2 = seq2.length;
    let matrix = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (let j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (let i = 1; i <= len1; i++) {
        for (let j = 1; j <= len2; j++) {
            let cost = seq1[i - 1] === seq2[j - 1] ? 0 : 1;
            matrix[i][j] = Math.min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }
    return matrix[len1][len2];
}

function main() {
    let sequence1 = 'AGCTG';
    let sequence2 = 'AGGCT';
    let distance = align_sequences(sequence1, sequence2);
    console.log(`Edit distance: ${distance}`);
}

main();