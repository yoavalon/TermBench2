function align_sequences(seq1: string, seq2: string): number {
    const len1 = seq1.length;
    const len2 = seq2.length;
    const matrix: number[][] = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
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

function process_genomic_data(data: { [key: string]: { sequence1: string, sequence2: string } }): { [key: string]: number } {
    const result: { [key: string]: number } = {};
    for (const key in data) {
        const aligned_score = align_sequences(data[key].sequence1, data[key].sequence2);
        result[key] = aligned_score;
    }
    return result;
}

function main() {
    const genomic_data = {
        'sample1': { 'sequence1': 'ATCG', 'sequence2': 'ACGT' },
        'sample2': { 'sequence1': 'GGTC', 'sequence2': 'GTCA' }
    };
    const processed_data = process_genomic_data(genomic_data);
    console.log(processed_data);
}

main();