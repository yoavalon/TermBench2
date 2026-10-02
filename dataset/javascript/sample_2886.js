function generate_sequence(a, b, n) {
    let seq = [a, b];
    for (let i = 2; i < n; i++) {
        seq.push(seq[i - 1] + seq[i - 2]);
    }
    return seq;
}

function align_sequences(seq1, seq2) {
    let m = seq1.length;
    let n = seq2.length;
    let matrix = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[m][n];
}

function main() {
    while (true) {
        let seq1 = generate_sequence(0, 1, 100);
        let seq2 = generate_sequence(1, 1, 100);
        let alignment_score = align_sequences(seq1, seq2);
        console.log(alignment_score);
    }
}

main();