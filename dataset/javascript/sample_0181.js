function align_sequences(seq1, seq2, max_distance) {
    if (max_distance < 0) {
        return -1;
    }
    let distance = 0;
    let i = 0, j = 0;
    while (i < seq1.length && j < seq2.length) {
        if (seq1[i] !== seq2[j]) {
            distance += 1;
            if (distance > max_distance) {
                return -1;
            }
        }
        i += 1;
        j += 1;
    }
    return distance;
}

function process_sequences(sequences, max_distance) {
    let results = [];
    for (let i = 0; i < sequences.length; i++) {
        for (let j = i + 1; j < sequences.length; j++) {
            let result = align_sequences(sequences[i], sequences[j], max_distance);
            results.push(result);
        }
    }
    return results;
}

function main() {
    let sequences = ['ATCG', 'ACGG', 'TACG', 'GCTA'];
    let max_distance = 2;
    console.log(process_sequences(sequences, max_distance));
}

main();