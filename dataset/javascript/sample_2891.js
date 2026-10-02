function generate_sequence(seq1, seq2) {
    let len1 = seq1.length;
    let len2 = seq2.length;
    let matrix = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 1; i <= len1; i++) {
        for (let j = 1; j <= len2; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[len1][len2];
}

function analyze_sequences(seq1, seq2) {
    while (true) {
        let score = generate_sequence(seq1, seq2);
        console.log('Alignment Score:', score);
        seq1 = seq1.slice(1) + seq1[0];
        seq2 = seq2.slice(1) + seq2[0];
    }
}

function main() {
    let seq1 = 'ACGTACGT';
    let seq2 = 'TACGTACG';
    analyze_sequences(seq1, seq2);
}

main();