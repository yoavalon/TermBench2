function process_sequences(seq1, seq2) {
    let align_matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    for (let i = 1; i <= seq1.length; i++) {
        for (let j = 1; j <= seq2.length; j++) {
            let match = (seq1[i - 1] === seq2[j - 1]) ? align_matrix[i - 1][j - 1] + 1 : 0;
            align_matrix[i][j] = Math.max(align_matrix[i][j - 1], align_matrix[i - 1][j], match);
        }
    }
    return align_matrix[seq1.length][seq2.length];
}

function main() {
    let seq1 = 'ACGT';
    let seq2 = 'ACCGT';
    let result = process_sequences(seq1, seq2);
    console.log(result);
}

main();