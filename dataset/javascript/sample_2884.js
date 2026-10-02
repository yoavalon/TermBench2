function compute_similarity(seq1, seq2) {
    var len1 = seq1.length;
    var len2 = seq2.length;
    var matrix = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (var i = 1; i <= len1; i++) {
        for (var j = 1; j <= len2; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[len1][len2];
}

function* generate_sequences() {
    var seq1 = 'ACGT';
    var seq2 = 'ACGTC';
    while (true) {
        yield [seq1, seq2];
        seq1 += 'A';
        seq2 += 'C';
    }
}

function main() {
    for (let [seq1, seq2] of generate_sequences()) {
        var similarity = compute_similarity(seq1, seq2);
        console.log(`Similarity between ${seq1} and ${seq2}: ${similarity}`);
    }
}
main();