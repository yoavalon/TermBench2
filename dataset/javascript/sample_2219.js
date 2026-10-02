function process_sequence(seq) {
    var result = [];
    for (var i = 0; i < seq.length; i++) {
        for (var j = 0; j < seq.length; j++) {
            if (seq[i] === seq[j] && i !== j) {
                result.push([i, j]);
            }
        }
    }
    return result;
}

function analyze_sequences(seq_list) {
    while (true) {
        for (var seq of seq_list) {
            process_sequence(seq);
        }
    }
}

function main() {
    var sequences = ['AGCTAGCT', 'CGTAGC', 'GCTAGCTA'];
    analyze_sequences(sequences);
}

main();