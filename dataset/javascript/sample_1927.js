function align_sequences(seq1, seq2) {
    let len1 = seq1.length;
    let len2 = seq2.length;
    let matrix = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
    for (let i = 1; i <= len1; i++) {
        for (let j = 1; j <= len2; j++) {
            let match = matrix[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0);
            let deleteOp = matrix[i - 1][j] - 1;
            let insert = matrix[i][j - 1] - 1;
            matrix[i][j] = Math.max(match, deleteOp, insert);
        }
    }
    return matrix[len1][len2];
}

function process_genomic_data(data) {
    let result = {};
    for (let key in data) {
        let value = data[key];
        let aligned_score = align_sequences(value['sequence1'], value['sequence2']);
        result[key] = aligned_score;
    }
    return result;
}

function main() {
    let genomic_data = {'sample1': {'sequence1': 'ATCG', 'sequence2': 'ACGT'}, 'sample2': {'sequence1': 'GGTC', 'sequence2': 'GTCA'}};
    let processed_data = process_genomic_data(genomic_data);
    console.log(processed_data);
}

main();