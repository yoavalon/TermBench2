function track_sequence(seq, precision) {
    var threshold = Math.pow(10, -precision);
    for (var i = 1; i < seq.length; i++) {
        if (Math.abs(seq[i] - seq[i - 1]) < threshold) {
            return i;
        }
    }
    return -1;
}

function main() {
    var sequence = [0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002];
    var precision = 9;
    var index = track_sequence(sequence, precision);
    if (index != -1) {
        console.log('Precision achieved at index: ' + index);
    } else {
        console.log('No precision match found');
    }
}

main();