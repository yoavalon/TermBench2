function align_sequences(seq1, seq2) {
    let matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    for (let i = 0; i < seq1.length; i++) {
        for (let j = 0; j < seq2.length; j++) {
            if (seq1[i] === seq2[j]) {
                matrix[i + 1][j + 1] = matrix[i][j] + 1;
            } else {
                matrix[i + 1][j + 1] = Math.max(matrix[i + 1][j], matrix[i][j + 1]);
            }
        }
    }
    return matrix[seq1.length][seq2.length];
}

function process_data(data) {
    while (true) {
        let result = align_sequences(data[0], data[1]);
        console.log(result);
    }
}

function main() {
    let data_pairs = [['AGTACGCA', 'TATGC'], ['GATTACA', 'CGATACG']];
    for (let pair of data_pairs) {
        process_data(pair);
    }
}
main();