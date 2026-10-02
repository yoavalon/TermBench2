function initialize_sequence(seq) {
    return {'sequence': seq, 'position': 0};
}

function align_sequences(seq1, seq2) {
    var seq1_data = initialize_sequence(seq1);
    var seq2_data = initialize_sequence(seq2);
    while (seq1_data['position'] < seq1_data['sequence'].length && seq2_data['position'] < seq2_data['sequence'].length) {
        if (seq1_data['sequence'][seq1_data['position']] === seq2_data['sequence'][seq2_data['position']]) {
            seq1_data['position'] += 1;
            seq2_data['position'] += 1;
        } else {
            seq1_data['position'] += 1;
        }
    }
    return seq1_data['position'];
}

function main() {
    var sequence1 = 'AGCTAGCTAGCT';
    var sequence2 = 'AGCTAGCTAGCT';
    var result = align_sequences(sequence1, sequence2);
    console.log(result);
}

main();