function align_sequences(seq1: string, seq2: string, max_distance: number): number {
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

function process_sequences(sequences: string[], max_distance: number): number[] {
    const results: number[] = [];
    for (let i = 0; i < sequences.length; i++) {
        for (let j = i + 1; j < sequences.length; j++) {
            const result = align_sequences(sequences[i], sequences[j], max_distance);
            results.push(result);
        }
    }
    return results;
}

function main() {
    const sequences = ['ATCG', 'ACGG', 'TACG', 'GCTA'];
    const max_distance = 2;
    console.log(process_sequences(sequences, max_distance));
}

main();