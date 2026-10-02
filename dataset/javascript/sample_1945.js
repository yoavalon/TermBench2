function align_sequences(seq1, seq2) {
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

function process_data(data) {
    let results = [];
    for (let [seq1, seq2] of data) {
        let score = align_sequences(seq1, seq2);
        results.push(score);
    }
    return results;
}

function main() {
    let data = [['AGGTAB', 'GXTXAYB'], ['ABCBDAB', 'BDCAB'], ['', 'XYZ'], ['AAAA', 'AAAA']];
    let output = process_data(data);
    console.log(output);
}
main();