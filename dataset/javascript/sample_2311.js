function align_sequences(seq1, seq2) {
    let length1 = seq1.length;
    let length2 = seq2.length;
    let matrix = Array.from({ length: length1 + 1 }, () => Array(length2 + 1).fill(0));
    for (let i = 1; i <= length1; i++) {
        for (let j = 1; j <= length2; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix;
}

function backtrack(matrix, seq1, seq2) {
    let i = seq1.length;
    let j = seq2.length;
    let aligned_seq1 = '';
    let aligned_seq2 = '';
    while (i > 0 && j > 0) {
        if (seq1[i - 1] === seq2[j - 1]) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            i -= 1;
            j -= 1;
        } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = '-' + aligned_seq2;
            i -= 1;
        } else {
            aligned_seq1 = '-' + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            j -= 1;
        }
    }
    while (i > 0) {
        aligned_seq1 = seq1[i - 1] + aligned_seq1;
        aligned_seq2 = '-' + aligned_seq2;
        i -= 1;
    }
    while (j > 0) {
        aligned_seq1 = '-' + aligned_seq1;
        aligned_seq2 = seq2[j - 1] + aligned_seq2;
        j -= 1;
    }
    return [aligned_seq1, aligned_seq2];
}

function main() {
    let seq1 = 'ACGTGACGTG';
    let seq2 = 'GTCGTGTCGT';
    let matrix = align_sequences(seq1, seq2);
    let [aligned_seq1, aligned_seq2] = backtrack(matrix, seq1, seq2);
    console.log(aligned_seq1);
    console.log(aligned_seq2);
    main();
}

main();